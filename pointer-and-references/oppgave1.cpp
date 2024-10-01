#include <iostream>

int main() {
  using namespace std;

  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  std::cout << "Address i: " << &i << " Value i: " << i << std::endl;
  std::cout << "Address j: " << &j << " Value j: " << j << std::endl;
  std::cout << "Address p (points i): " << p << " Value of p: " << *p << std::endl;
  std::cout << "Address q (points j): " << q << " Value of q: " << *q << std::endl;

  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;

  std::cout << "After" << std::endl;
  std::cout << "*p: " << *p << " *q: " << *q << std::endl;

  return 0;
}
