#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &fraction) {
  cout << text << fraction.numerator << " / " << fraction.denominator << endl;
}

int main() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d) {
    cout << "a + b != c + d" << endl;
  } else {
    cout << "a + b == c + d" << endl;
  }

  while (b > a) {
    b -= a;
  }
  print("b = ", b);

  Fraction result1 = a - 5;
  print("a - 5 = ", result1);

  Fraction result2 = 5 - a;
  print("5 - a = ", result2);

  Fraction result3 = 5 - 3 - a - 7 - b;
  print("5 - 3 - a - 7 - b = ", result3);

  return 0;
}
