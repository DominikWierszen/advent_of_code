#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main(int argc, char *argv[]) {
  string data;
  int ans = 0;
  ifstream myFile;
  myFile.open("data.txt");
  bool sorted = false;
  string wholeLine = "";
  while (getline(myFile, data)) {
    wholeLine += data;
  }
  regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
  smatch match;
  bool completeOperation = true;
  std::string::const_iterator currentPosition(wholeLine.cbegin());
  while (std::regex_search(currentPosition, wholeLine.cend(), match, pattern)) {

    ans += stoi(match[1]) * stoi(match[2]);
    currentPosition = match.suffix().first;
  }
  myFile.close();
  cout << ans;
  return 0;
}
