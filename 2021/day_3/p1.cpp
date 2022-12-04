#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  ifstream ifile;
  ifile.open("data.txt");

  vector<string> bnums;
  string bnum;
  while (ifile >> bnum) {
    bnums.push_back(bnum);
  }

  string gamma_rate = "", epilson_rate = "";
  // loops through string
  for (int i = 0; i < bnums[i].size(); i++) {
    int zeroes = 0;
    // loops through strings
    for (int j = 0; j < bnums.size(); j++) {
      if (bnums[j].at(i) == *"0")
        zeroes++;
    }
    if (zeroes > bnums.size() / 2) {
      gamma_rate += "0";
      epilson_rate += "1";
    } else {
      gamma_rate += "1";
      epilson_rate += "0";
    }
  }
  ifile.close();
  // cout << gamma_rate << "  " << epilson_rate;
  cout << (int)std::stoi(gamma_rate, nullptr, 2) *
              (int)std::stoi(epilson_rate, nullptr, 2);
  return 0;
}
