#pragma once
#include <iostream>
#include <vector>

class Set {
public:
  Set();
  Set(const Set &other);
  Set &operator=(const Set &other);
  Set operator+(const Set &other) const;
  void add(int value);
  bool exists(int value) const;

  friend std::ostream &operator<<(std::ostream &os, const Set &set);

private:
  std::vector<int> elements;
};
