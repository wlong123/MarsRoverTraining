#include "rational.h"
#include <iostream>

Rational::Rational(int a, int b) : num(a), den(b) {}

double Rational::value() const {
  return static_cast<double>(num)/den;
}

int Rational::getDenominator() const {
  return den;
}

int Rational::getNumerator() const {
  return num;
}

const int gcd(int a, int b) {
  if(b == 0)
    return a;
  else
    return gcd(b, a % b);
}

const int lcm(int a, int b) {
  return a * b /gcd(a,b);
}

Rational operator+(const Rational& r1, const Rational& r2) {
  int commonDenominator = lcm(r1.getDenominator(), r2.getDenominator());
  int newNumerator = r1.getNumerator() * commonDenominator / r1.getDenominator()
                  + r2.getNumerator() * commonDenominator / r2.getDenominator();
  return Rational(newNumerator, commonDenominator);
}

Rational operator-(const Rational& r1, const Rational& r2) {
  int commonDenominator = lcm(r1.getDenominator(), r2.getDenominator());
  int newNumerator = r1.getNumerator() * commonDenominator / r1.getDenominator()
                  - r2.getNumerator() * commonDenominator / r2.getDenominator();
  return Rational(newNumerator, commonDenominator);
}

Rational operator*(const Rational& r1, const Rational& r2) {
  int newDenominator = r1.getDenominator() * r2.getDenominator();
  int newNumerator = r1.getNumerator() * r2.getNumerator();
  return Rational(newNumerator, newDenominator);
}

Rational operator/(const Rational& r1, const Rational& r2) {
  int newNumerator = r1.getNumerator() * r2.getDenominator();
  int newDenominator = r1.getDenominator() * r2.getNumerator();
  return Rational(newNumerator, newDenominator);
}

bool operator==(const Rational& r1, const Rational& r2) {
  return r1.value() == r2.value();
}

int main() {
  Rational one_half(1,2);
  Rational one_third(1,3);
  Rational two_thirds(2,3);
  Rational sum = one_half + two_thirds;
  Rational minus = one_half - two_thirds;
  Rational product = one_half * two_thirds;
  Rational divide = one_half / two_thirds;
  bool e = one_half == one_half;
  bool n = one_half == two_thirds;
  std::cout << one_half.value() << std::endl;
  std::cout << one_third.value() << std::endl;
  std::cout << two_thirds.value() << std::endl;
  std::cout << sum.value() << std::endl;
  std::cout << minus.value() << std::endl;
  std::cout << product.value() << std::endl;
  std::cout << divide.value() << std::endl;
  std::cout << e << std::endl;
  std::cout << n << std::endl;
  return 0;
}