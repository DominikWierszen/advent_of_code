#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  ifstream ifile;
  ifile.open("example_data.txt");

  vector<string> bnums;
  string bnum;
  while (ifile >> bnum) {
    bnums.push_back(bnum);
  }

  vector<string> data2 = bnums;
  int i2 = 0;
  while (data2.size() > 1) {
    int one = 0;
    int zero = 0;
    vector<string> ones = {};
    vector<string> zeroes = {};
    for (int i = 0; i < data2.size(); i++) {
      if (data2[i].at(i2) == '0') {
        zero++;
        zeroes.push_back(data2[i]);
      } else {
        one++;
        ones.push_back(data2[i]);
      }

      if (zero == one) {
        data2 = zeroes;
      } else if (zero > one) {
        data2 = ones;
      } else {
        data2 = ones;
      }
    }
    i2++;
  }
  cout << data2.size();

  string oxygen = data2[0];
  cout << oxygen;

  ifile.close();
  // cout << (int)std::stoi(oxygen, nullptr, 2);

  // answer
  // cout << (int)std::stoi(oxygen_rate, nullptr, 2) *
  //             (int)std::stoi(co2_rate, nullptr, 2);
  return 0;
}
