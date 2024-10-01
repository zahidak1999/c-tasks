#include <iostream>

int main() {
  using namespace std;

  double number = 0;

  double *ptr = &number;

  double &ref = number;

  number = 10;
  cout << "Tilordnet direkte: " << number << endl;

  *ptr = 20;
  cout << "Tilordnet peker: " << number << endl;

  ref = 30;
  cout << "Tilordnet referanse: " << number << endl;

  return 0;
}
