#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string data;
  int num1, num2, ans = 0;
  ifstream myFile;
  myFile.open("data.txt");

  vector<pair<int, int>> rules;
  // store rules
  while (getline(myFile, data) && !data.empty()) {
    replace(data.begin(), data.end(), '|', ' ');
    istringstream(data) >> num1 >> num2;
    rules.push_back({num1, num2});
  }

  vector<vector<int>> updates;
  // store pages
  while (getline(myFile, data)) {
    replace(data.begin(), data.end(), ',', ' ');
    istringstream ss(data);
    int num;
    vector<int> line;
    while (ss >> num) {
      line.push_back(num);
    }
    updates.push_back(line);
  }

  myFile.close();

  for (int i = 0; i < updates.size(); i++) {
    bool check = true;
    for (int k = 0; k < rules.size(); k++) {
      auto [value1, value2] = rules[k];

      auto itvalue1 = find(updates[i].begin(), updates[i].end(), value1);
      auto itvalue2 = find(updates[i].begin(), updates[i].end(), value2);

      // checks if the rule values are in the updates and if value 1 comes
      // before value value2
      if (itvalue1 != updates[i].end() && itvalue2 != updates[i].end() &&
          !(itvalue1 < itvalue2)) {
        check = false;
        break;
      }
    }
    if (check) {
      ans += updates[i][updates[i].size() / 2];
    }
  }
  cout << ans;
  return 0;
}
