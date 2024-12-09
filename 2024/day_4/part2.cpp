#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  string data;
  vector<vector<char>> list;
  ifstream myFile;
  myFile.open("data.txt");

  while (getline(myFile, data)) {
    vector<char> temp;
    for (auto c : data) {
      temp.push_back(c);
    }
    list.push_back(temp);
  }

  int ans = 0;
  for (size_t i = 0; i < list.size(); ++i) {
    for (size_t j = 0; j < list[i].size(); ++j) {
      if (list[i][j] == 'A') {
      }
    }
  }

  // for (auto l : list) {
  //   for (auto c : l) {
  //     cout << c;
  //   }
  //   cout << endl;
  // }
  cout << ans;
  myFile.close();
  return 0;
}
