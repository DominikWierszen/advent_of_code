#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool isIncOrDec(vector<int> list) {
  if (std::is_sorted(list.begin(), list.end()) &&
      std::adjacent_find(list.begin(), list.end()) == list.end()) {
    return true;
  }
  if (std::is_sorted(list.rbegin(), list.rend()) &&
      std::adjacent_find(list.rbegin(), list.rend()) == list.rend()) {
    return true;
  }

  return false;
}

bool isSafe(vector<int> list) {
  if (!isIncOrDec(list)) {
    return false;
  }
  for (int i = 0; i < list.size() - 1; i++) {
    if (list[i] > list[i + 1]) {
      if (list[i] - list[i + 1] <= 3 && list[i] - list[i + 1] >= 0)
        continue;
      else
        return false;
    } else {
      if (list[i + 1] - list[i] <= 3 && list[i + 1] - list[i] >= 0)
        continue;
      else
        return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  string data;
  int num, ans = 0;
  ifstream myFile;
  myFile.open("data.txt");
  vector<int> list;
  bool sorted = false;
  while (getline(myFile, data)) {
    istringstream iss(data);
    while (iss >> num) {
      list.push_back(num);
    }
    if (isSafe(list)) {
      ans++;
    } else {
      for (int i = 0; i < list.size(); i++) {
        vector<int> tempList = list;
        tempList.erase(tempList.begin() + i);

        if (isSafe(tempList)) {
          ans++;
          break;
        }
      }
    }
    list.clear();
  }

  myFile.close();
  cout << ans;
  return 0;
}
