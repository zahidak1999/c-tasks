#include <iostream>

int find_sum(const int *table, int length) {
  int sum = 0;
  for(int i = 0; i < length; i++) {
    sum += table[i];
  }
  return sum;
}

int main() {
  using namespace std;

  int table[20];

  for(int i = 0; i < 20; i++) {
    table[i] = i + 1;
  }

  int sum_first_10 = find_sum(table, 10);
  cout << "Summen av de 10 første tallene: " << sum_first_10 << endl;

  int sum_next_5 = find_sum(table + 10, 5);
  cout << "Summen av de 5 neste tallene: " << sum_next_5 << endl;

  int sum_last_5 = find_sum(table + 15, 5);
  cout << "Summen av de 5 siste tallene: " << sum_last_5 << endl;

  return 0;
}
