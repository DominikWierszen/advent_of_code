#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int max = 0;
  vector<int> current;
  vector<int> ans;
  vector<vector<int>> elves;
  string calories;
  ifstream myFile;
  myFile.open("data.txt");
  while (getline(myFile, calories)) {
    if (calories.empty()) {
      elves.push_back(current);
      current = {};
    } else {
      current.push_back(stoi(calories));
    }
  }

  for (auto i : elves) {
    int temp = 0;
    for (auto x : i) {

      temp += x;
    }
    ans.push_back(temp);
  }

  sort(ans.begin(), ans.end(), greater<>());

  myFile.close();
  cout << ans[0] + ans[1] + ans[2];
  return 0;
}
