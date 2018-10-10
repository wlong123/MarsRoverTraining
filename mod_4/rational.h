#pragma once

class Rational {
  int num;
  int den;
  const int gcd(int a, int b);
  const int lcm(int a, int b);
  const Rational reduce();
  public:
    Rational(int a, int b);
    double value() const;
    int getNumerator() const;
    int getDenominator() const;
};