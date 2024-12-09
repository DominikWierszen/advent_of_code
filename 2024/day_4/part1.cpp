#include <bits/stdc++.h>

using namespace std;

bool right(vector<vector<char>> list, int i, int j) {
  if (j <= list[i].size() - 4 && list[i][j + 1] == 'M' &&
      list[i][j + 2] == 'A' && list[i][j + 3] == 'S') {
    return true;
  }
  return false;
}

bool left(vector<vector<char>> list, int i, int j) {
  if (j >= 3 && list[i][j - 1] == 'M' && list[i][j - 2] == 'A' &&
      list[i][j - 3] == 'S') {
    return true;
  }
  return false;
}

bool up(vector<vector<char>> list, int i, int j) {
  if (i >= 3 && list[i - 1][j] == 'M' && list[i - 2][j] == 'A' &&
      list[i - 3][j] == 'S') {
    return true;
  }
  return false;
}

bool down(vector<vector<char>> list, int i, int j) {
  if (i <= list.size() - 4 && list[i + 1][j] == 'M' && list[i + 2][j] == 'A' &&
      list[i + 3][j] == 'S') {
    return true;
  }
  return false;
}

bool downright(vector<vector<char>> list, int i, int j) {
  if (i <= list.size() - 4 && j <= list[i].size() - 4 &&
      list[i + 1][j + 1] == 'M' && list[i + 2][j + 2] == 'A' &&
      list[i + 3][j + 3] == 'S') {
    return true;
  }
  return false;
}

bool downleft(vector<vector<char>> list, int i, int j) {
  if (i <= list.size() - 4 && j >= 3 && list[i + 1][j - 1] == 'M' &&
      list[i + 2][j - 2] == 'A' && list[i + 3][j - 3] == 'S') {
    return true;
  }
  return false;
}

bool upleft(vector<vector<char>> list, int i, int j) {
  if (i >= 3 && j >= 3 && list[i - 1][j - 1] == 'M' &&
      list[i - 2][j - 2] == 'A' && list[i - 3][j - 3] == 'S') {
    return true;
  }
  return false;
}

bool upright(vector<vector<char>> list, int i, int j) {
  if (i >= 3 && j <= list[i].size() - 4 && list[i - 1][j + 1] == 'M' &&
      list[i - 2][j + 2] == 'A' && list[i - 3][j + 3] == 'S') {
    return true;
  }
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
  for (size_t i = 0; i < list.size(); ++i) {
    for (size_t j = 0; j < list[i].size(); ++j) {
      if (list[i][j] == 'X') {
        if (right(list, i, j))
          ans++;
        if (left(list, i, j))
          ans++;
        if (up(list, i, j))
          ans++;
        if (down(list, i, j))
          ans++;
        if (downright(list, i, j))
          ans++;
        if (downleft(list, i, j))
          ans++;
        if (upright(list, i, j))
          ans++;
        if (upleft(list, i, j))
          ans++;
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
