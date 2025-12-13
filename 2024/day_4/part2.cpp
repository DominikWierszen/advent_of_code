#include <bits/stdc++.h>
using namespace std;

bool check_xmas(vector<vector<char>> list, int i, int j) {
  if (((list[i + 1][j + 1] == 'M' && list[i - 1][j - 1] == 'S') ||
       (list[i + 1][j + 1] == 'S' && list[i - 1][j - 1] == 'M')) &&
      ((list[i - 1][j + 1] == 'M' && list[i + 1][j - 1] == 'S') ||
       (list[i - 1][j + 1] == 'S' && list[i + 1][j - 1] == 'M')))
    return true;
  return false;
}

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
  for (int i = 1; i < list.size() - 1; ++i) {
    for (int j = 1; j < list[i].size() - 1; ++j) {
      if (list[i][j] == 'A') {
        if (check_xmas(list, i, j))
          ans++;
      }
    }
  }

  cout << ans;
  myFile.close();
  return 0;
}
