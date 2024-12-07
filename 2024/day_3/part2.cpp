#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main(int argc, char *argv[]) {
  string data;
  int ans = 0;
  ifstream myFile;

  myFile.open("data.txt");
  string wholeLine = "";

  bool completeOperation = true;
  regex pattern(R"((do\(\))|(don't\(\))|(mul\((\d+),(\d+)\)))");
  smatch match;

  while (getline(myFile, data)) {

    auto begin = data.cbegin();
    auto end = data.cend();

    while (regex_search(begin, end, match, pattern)) {

      if (match[1].matched) {
        completeOperation = true;
      }
      if (match[2].matched) {
        completeOperation = false;
      }

      if (match[3].matched && completeOperation) {
        int x = stoi(match[4]);
        int y = stoi(match[5]);
        ans += static_cast<long long>(x) * y;
      }
      begin = match.suffix().first;
    }
  }
  myFile.close();
  cout << ans;
  return 0;
}
