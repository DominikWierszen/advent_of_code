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
  ifile.close();
  string oxygen_generator_rate = "", co2_scrubber__rate = "";

  vector<string> oxygen;
  vector<string> co2;

  // loops through string
  while (bnums.size() > 1) {
    int j = 0;
    int zeroes = 0;
    int ones = 0;
    // loops through strings
    for (int i = 0; i < bnums.size(); i++) {
      if (bnums[i].at(j) == *"0") {
        zeroes++;

      } else {
        ones++;
      }
      if (zeroes > bnums.size() / 2) {
        oxygen_generator_rate += "0";
        co2_scrubber__rate += "1";
      } else if (zeroes < bnums.size() / 2) {
        oxygen_generator_rate += "1";
        co2_scrubber__rate += "0";
      } else {
        oxygen_generator_rate += "1";
        co2_scrubber__rate += "0";
      }
    }

    cout << (int)std::stoi(oxygen_generator_rate, nullptr, 2) *
                (int)std::stoi(co2_scrubber__rate, nullptr, 2);
    return 0;
  }
