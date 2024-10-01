#include <fstream>
#include <iostream>

void read_temperatures(double temperatures[], int length);

int main() {
  const int length = 5;
  double temperatures[length];

  read_temperatures(temperatures, length);

  int countUnder10 = 0;
  int countBetween10And20 = 0;
  int countOver20 = 0;

  for(int i = 0; i < length; ++i) {
    if(temperatures[i] < 10) {
      countUnder10++;
    }
    else if(temperatures[i] >= 10 && temperatures[i] <= 20) {
      countBetween10And20++;
    }
    else {
      countOver20++;
    }
  }

  std::cout << "Antall under 10 er " << countUnder10 << std::endl;
  std::cout << "Antall mellom 10 og 20 er " << countBetween10And20 << std::endl;
  std::cout << "Antall over 20 er " << countOver20 << std::endl;

  return 0;
}

void read_temperatures(double temperatures[], int length) {
  std::ifstream infile("temperatures.txt");

  for(int i = 0; i < length; ++i) {
    infile >> temperatures[i];
  }

  infile.close();
}
