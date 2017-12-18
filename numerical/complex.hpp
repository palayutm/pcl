#include <bits/stdc++.h>

template <class T> struct Complex {
  T real, imag;
  Complex() { real = imag = 0; }
  Complex(T real, T imag) : real(real), imag(imag) {}
  Complex<T>& operator=(const double& o) { real = o, imag = 0; return *this;}
  Complex<T> operator+(const Complex<T>& o) const { return Complex<T>(real + o.real, imag + o.imag); }
  Complex<T> operator-(const Complex<T>& o) const { return Complex<T>(real - o.real, imag - o.imag); }
  Complex<T> operator*(const Complex<T>& o) const { return Complex<T>(real * o.real - imag * o.imag, real * o.imag + imag * o.real); }
  friend Complex<T> conj(const Complex<T>& a) { return Complex<T>(a.real, -a.imag); }
};
