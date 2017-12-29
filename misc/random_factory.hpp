#pragma once
#include <bits/stdc++.h>
#include "../number-theory/miller_rabin.hpp"

class RandomFactory {
public:
  static RandomFactory& getInstance() {
    static RandomFactory rf;
    return rf;
  }

  static long long randomInteger(long long left = 1, long long right = 1e9) {
    std::uniform_int_distribution<long long> uid(left, right);
    return uid(gen);
  }

  static int randomPrime(int left = 1, int right = 1e9) {
    int cnt = 100000;
    for (; --cnt;) {
      int k = randomInteger(left, right);
      if (miller_rabin::millerRabin(k)) {
        return k;
      }
    }
    assert(false);
  }
  
private:
  RandomFactory(){}
  static std::mt19937 gen;
};
std::mt19937 RandomFactory::gen((std::random_device())());
