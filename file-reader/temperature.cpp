#include <iostream>

int main() {
  const int length = 5;
  double temp;
  int countUnder10 = 0;
  int countBetween10And20 = 0;
  int countOver20 = 0;

  std::cout << "Du skal skrive inn " << length << " temperaturer. " << std::endl;

  for(int i = 1; i <= length; i++) {
    std::cout << "Temperatur nr " << i << ": ";
    std::cin >> temp;

    if(temp < 10) {
      countUnder10++;
    }
    else if(temp >= 10 && temp <= 20) {
      countBetween10And20++;
    }
    else {
      countOver20++;
    }
  }

  std::cout << "Antall temperaturer under 10 grader: " << countUnder10 << std::endl;
  std::cout << "Antall temperaturer mellom 10 og 20 grader: " << countBetween10And20 << std::endl;
  std::cout << "Antall temperaturer over 20 grader: " << countOver20 << std::endl;

  return 0;
}
