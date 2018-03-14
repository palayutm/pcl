#include "catch.hpp"
#include "../misc/random_factory.hpp"
#include "../number-theory/exgcd.hpp"
#include "../number-theory/euler_totient_function.hpp"
#include "../number-theory/inverse.hpp"
#include "../number-theory/prime_sieve.hpp"
#include "../number-theory/prime_count_function.hpp"

TEST_CASE("Euler’s Totient Function under 1e6") {
  auto phi = preTotient(1000001);
  for (int i = 1; i <= 1000000; i++) {
    REQUIRE(phi[i] == totient(i));
  }
}

TEST_CASE("Extend Euclid under 1e9 (random 1e5 case)") {
  for (int i = 0; i < 100000; i++) {
    int a = RandomFactory::randomInteger(), b = RandomFactory::randomInteger();
    long long x, y;
    int d = exgcd(a, b, x, y);
    REQUIRE(d == std::__gcd(a, b));
    REQUIRE(a * x + b * y == d);
  }
}

TEST_CASE("Extend Euclid under 1e18 (random 1e5 case)") {
  for (int i = 0; i < 100000; i++) {
    long long a = RandomFactory::randomInteger(1, 1e18), b = RandomFactory::randomInteger(1, 1e18);
    long long x, y;
    long long d = exgcd(a, b, x, y);
    REQUIRE(d == std::__gcd(a, b));
    REQUIRE((__int128)a * x + (__int128)b * y == d);
  }
}

TEST_CASE("Modular multiplicative inverse (random 1e6 non-prime case)") {
  for (int i = 0; i < 100000; i++) {
    int x = RandomFactory::randomInteger(), y = RandomFactory::randomInteger();
    int g = std::__gcd(x, y);
    x /= g, y /= g;
    if (y != 1) {
      int inv = inverse::non_prime_mod::inverse(x, y);
      REQUIRE((long long)x * inv % y == 1);
    }
  }
}

TEST_CASE("Modular multiplicative inverse (random 1e3 prime case)") {
  for (int i = 0; i < 1000; i++) {
    int p = RandomFactory::randomPrime();
    int x = RandomFactory::randomInteger(1, p - 1);
    int inv = inverse::prime_mod::inverse(x, p);
    REQUIRE((long long)x * inv % p == 1);
  }
}

TEST_CASE("Modular multiplicative inverse (pre calculate under 1e5, random 10 case)") {
  for (int z = 0; z < 10; z++) {
    int p = RandomFactory::randomPrime(1e6, 1e9);
    auto inv = inverse::prime_mod::preInverse(1e5, p);
    for (int i = 1; i <= 1e5; i++) {
      REQUIRE((long long)i * inv[i] % p == 1);
    }
  }
}

TEST_CASE("Prime Count Function (under 1e8, random 10 case)") {
  for (int i = 0; i < 10; i++) {
    int n = RandomFactory::randomInteger(1, 1e8);
    auto is_prime = primeSieve(n).first;
    std::vector<int> pre_sum(n + 1);
    for (int i = 1; i <= n; i++) {
      pre_sum[i] = pre_sum[i - 1] + is_prime[i];
    }
    std::vector<long long> f, g;
    tie(f, g) = sieve(n);
    for (int i = 1; i * i <= n; i++) {
      REQUIRE(f[i] == pre_sum[i]);
      REQUIRE(g[i] == pre_sum[n / i]);
    }
  }
}

TEST_CASE("Prime Sieve (under 1e6)") {
  auto is_prime = primeSieve(1e6).first;
  for (int i = 1; i <= 1e6; i++) {
    REQUIRE(is_prime[i] == miller_rabin::isPrime(i));
  }
}

TEST_CASE("Linear Prime Sieve Time(under 2e8)") {
  auto is_prime = primeSieve(2e8).first;
}

TEST_CASE("Simple Prime Sieve Time(under 2e8)") {
  std::vector<bool> prime(2e8 + 1);
  std::vector<int> prime_list;
  for (int i = 2; i <= 200000000; i++) {
    if (!prime[i]) {
      prime_list.push_back(i);
      for (int j = i; (long long)j * i <= 200000000; j++) {
        prime[j * i] = true;
      }
    }
  }
} 

TEST_CASE("Primelity Test (under 1e12, random 1000 case)") {
  for (int i = 0; i < 1000; i++) {
    long long n = RandomFactory::randomInteger(1, 1e12);
    REQUIRE(miller_rabin::isPrime(n) == miller_rabin::millerRabin(n));
  }
}
