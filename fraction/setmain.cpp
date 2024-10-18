#include "set.hpp"
#include <iostream>

int main() {
  Set set1;
  Set set2;

  set1.add(1);
  set1.add(3);
  set1.add(4);

  set2.add(4);
  set2.add(7);

  std::cout << "Set 1: " << set1 << std::endl;
  std::cout << "Set 2: " << set2 << std::endl;

  Set unionSet = set1 + set2;
  std::cout << "Set 1 and Set 2: " << unionSet << std::endl;

  set1 = set2;
  std::cout << "Set 1 = Set 2: " << set1 << std::endl;

  return 0;
}
