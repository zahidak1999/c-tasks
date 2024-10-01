#include <iostream>

int main() {
  using namespace std;

  int a = 5;

  // Referansen må peke til en eksisterende variabel
  int &b = a;

  // Vi må peke til en adresse, ikke direkte til en referanse. Denne setter adressen for c til a, som peker til b
  int *c;
  c = &a;

  // Variabel 'a' er ikke en peker, men en int. 'b' referer til a som er 5, og c er peker til referansen til a som er 5.
  a = b + *c;

  cout << "a: " << a << ", b: " << b << ", *c: " << *c << endl;

  // Variabel 'b' blir nå 2.
  b = 2;

  // 'b' refererer til 'a' som er nå blitt to, c peker fortsatt mot a som er også blitt 2.
  cout << "a: " << a << ", b: " << b << ", *c: " << *c << endl;

  return 0;
}
