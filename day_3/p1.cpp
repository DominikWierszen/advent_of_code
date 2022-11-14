#include <fstream>
#include <iostream>
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

  // cout <<  gamma_rate * epilson_rate;
  return 0;
}
