#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifile;
  ifile.open("data.txt");

  vector<string> bnums;
  string bnum;
  int power_consumption, gamma_rate, epilson_rate, zeroes;
  while (ifile >> bnum) {
    bnums.push_back(bnum);
  }

  for (string a : bnums) {
    for (char b : a) {
      if (b == '0') {
        zeroes++;
      }
    }
  }

  ifile.close();

  power_consumption = gamma_rate * epilson_rate;
  cout << power_consumption;
  return 0;
}
