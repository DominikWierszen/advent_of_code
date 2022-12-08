#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream myFile;
  myFile.open("data.txt");
  string word;
  string half1, half2;
  vector<vector<string>> halves;

  while (myFile >> word) {
    half1 = word.substr(0, word.length() / 2);
    half2 = word.substr(word.length() / 2);
    halves.push_back({half1, half2});
  }

  for (auto x : halves) {
    for (auto i : x) {
      for (auto f : i) {
      }
    }
  }

  myFile.close();
  return 0;
}
