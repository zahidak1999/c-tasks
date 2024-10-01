#include <iostream>
#include <string>

using namespace std;

int main() {
  // a) Les inn tre ord fra brukeren
  string word1, word2, word3;
  cout << "Skriv inn tre ord: ";
  cin >> word1 >> word2 >> word3;

  // b) Skjøt sammen ordene med mellomrom og punktum på slutten
  string sentence = word1 + " " + word2 + " " + word3 + ".";
  cout << "Setningen er: " << sentence << endl;

  // c) Skriv ut lengden til hvert ord og hele setningen
  cout << "Lengden til hvert ord:\n";
  cout << word1 << ": " << word1.length() << endl;
  cout << word2 << ": " << word2.length() << endl;
  cout << word3 << ": " << word3.length() << endl;
  cout << "Lengden til hele setningen: " << sentence.length() << endl;

  // d) Lag en kopi av sentence
  string sentence2 = sentence;

  // e) Bytt ut tegn nr 10-12 i sentence2 med x'er, sjekk gyldige posisjoner
  if(sentence.length() >= 13) { // sjekker at setningen har minst 13 tegn
    sentence2[10] = 'x';
    sentence2[11] = 'x';
    sentence2[12] = 'x';
  }
  cout << "Original setning: " << sentence << endl;
  cout << "Modifisert setning: " << sentence2 << endl;

  // f) Lagre de fem første tegnene i sentence i sentence_start
  string sentence_start;
  if(sentence.length() >= 5) {
    sentence_start = sentence.substr(0, 5); // tar de første 5 tegnene
  }
  cout << "Original setning: " << sentence << endl;
  cout << "De første 5 tegnene: " << sentence_start << endl;

  // g) Finn ut om sentence inneholder ordet "hallo"
  if(sentence.find("hallo") != string::npos) {
    cout << "Setningen inneholder ordet 'hallo'" << endl;
  }
  else {
    cout << "Setningen inneholder ikke ordet 'hallo'" << endl;
  }

  // h) Finn alle forekomster av "er" i setningen
  size_t pos = sentence.find("er");
  if(pos == string::npos) {
    cout << "Setningen inneholder ikke 'er'" << endl;
  }
  else {
    cout << "'er' finnes i posisjonene: ";
    while(pos != string::npos) {
      cout << pos << " ";
      pos = sentence.find("er", pos + 1); // finn neste forekomst av "er"
    }
    cout << endl;
  }

  return 0;
}
