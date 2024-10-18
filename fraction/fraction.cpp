#include "fraction.hpp"
#include <cmath>
#include <iostream>

using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator, int denominator) {
  set(numerator, denominator);
}

void Fraction::set(int numerator_, int denominator_) {
  if (denominator_ != 0) {
    numerator = numerator_;
    denominator = denominator_;
    reduce();
  } else {
    throw "Denominator cannot be zero!";
  }
}

Fraction Fraction::operator-(int value) const {
  Fraction result;
  result.set(numerator - value * denominator, denominator);
  return result;
}

Fraction operator-(int value, const Fraction &fraction) {
  Fraction result;
  result.set(value * fraction.denominator - fraction.numerator, fraction.denominator);
  return result;
}

Fraction Fraction::operator+(const Fraction &other) const {
  Fraction fraction = *this;
  fraction += other;
  return fraction;
}

Fraction &Fraction::operator+=(const Fraction &other) {
  set(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator);
  return *this;
}

Fraction &Fraction::operator++() {
  numerator += denominator;
  return *this;
}

Fraction Fraction::operator-(const Fraction &other) const {
  Fraction fraction = *this;
  fraction -= other;
  return fraction;
}

Fraction &Fraction::operator-=(const Fraction &other) {
  set(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator);
  return *this;
}

Fraction &Fraction::operator--() {
  numerator -= denominator;
  return *this;
}

Fraction Fraction::operator-() const {
  Fraction fraction;
  fraction.numerator = -numerator;
  fraction.denominator = denominator;
  return fraction;
}

Fraction Fraction::operator*(const Fraction &other) const {
  Fraction fraction = *this;
  fraction *= other;
  return fraction;
}

Fraction &Fraction::operator*=(const Fraction &other) {
  set(numerator * other.numerator, denominator * other.denominator);
  return *this;
}

Fraction Fraction::operator/(const Fraction &other) const {
  Fraction fraction = *this;
  fraction /= other;
  return fraction;
}

Fraction &Fraction::operator/=(const Fraction &other) {
  set(numerator * other.denominator, denominator * other.numerator);
  return *this;
}

Fraction &Fraction::operator=(const Fraction &other) {
  numerator = other.numerator;
  denominator = other.denominator;
  return *this;
}

bool Fraction::operator==(const Fraction &other) const {
  return (compare(other) == 0);
}

bool Fraction::operator!=(const Fraction &other) const {
  return (compare(other) != 0);
}

bool Fraction::operator<=(const Fraction &other) const {
  return (compare(other) <= 0);
}

bool Fraction::operator>=(const Fraction &other) const {
  return (compare(other) >= 0);
}

bool Fraction::operator<(const Fraction &other) const {
  return (compare(other) < 0);
}

bool Fraction::operator>(const Fraction &other) const {
  return (compare(other) > 0);
}

void Fraction::reduce() {
  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }
  int a = abs(numerator);
  int b = denominator;
  int c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  numerator /= a;
  denominator /= a;
}

int Fraction::compare(const Fraction &other) const {
  Fraction fraction = *this - other;
  if (fraction.numerator > 0)
    return 1;
  else if (fraction.numerator == 0)
    return 0;
  else
    return -1;
}
