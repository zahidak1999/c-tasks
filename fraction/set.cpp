#include "set.hpp"
#include <algorithm>

Set::Set() {}

Set::Set(const Set &other) {
  elements = other.elements;
}

Set &Set::operator=(const Set &other) {
  if (this != &other) {
    elements = other.elements;
  }
  return *this;
}

void Set::add(int value) {
  if (!exists(value)) {
    elements.push_back(value);
  }
}

bool Set::exists(int value) const {
  return std::find(elements.begin(), elements.end(), value) != elements.end();
}

Set Set::operator+(const Set &other) const {
  Set result = *this;
  for (int val : other.elements) {
    result.add(val);
  }
  return result;
}

std::ostream &operator<<(std::ostream &os, const Set &set) {
  os << "{ ";
  for (int val : set.elements) {
    os << val << " ";
  }
  os << "}";
  return os;
}
