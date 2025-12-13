#include <bits/stdc++.h>

using namespace std;

vector<int> topological_sort(vector<int> &update,
                             vector<pair<int, int>> &rules) {
  unordered_map<int, unordered_set<int>> adj_list;
  unordered_map<int, int> in_degree;

  for (auto [u, v] : rules) {
    if (find(update.begin(), update.end(), u) != update.end() &&
        find(update.begin(), update.end(), v) != update.end()) {
      adj_list[u].insert(v);
      in_degree[v]++;
    }
  }

  queue<int> q;
  for (int page : update) {
    if (in_degree[page] == 0) {
      q.push(page);
    }
  }

  vector<int> sorted;
  while (!q.empty()) {
    int page = q.front();
    q.pop();
    sorted.push_back(page);
    for (int neighbor : adj_list[page]) {
      if (--in_degree[neighbor] == 0) {
        q.push(neighbor);
      }
    }
  }

  return sorted;
}

int main() {
  ifstream myFile("data.txt");
  string data;
  int num1, num2, ans = 0;

  vector<pair<int, int>> rules;
  // Store rules
  while (getline(myFile, data) && !data.empty()) {
    replace(data.begin(), data.end(), '|', ' ');
    istringstream(data) >> num1 >> num2;
    rules.push_back({num1, num2});
  }

  vector<vector<int>> updates;
  // Store pages
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
    for (auto [value1, value2] : rules) {
      auto itvalue1 = find(updates[i].begin(), updates[i].end(), value1);
      auto itvalue2 = find(updates[i].begin(), updates[i].end(), value2);

      if (itvalue1 != updates[i].end() && itvalue2 != updates[i].end() &&
          !(itvalue1 < itvalue2)) {
        check = false;
        break;
      }
    }
    if (!check) {
      vector<int> corrected_update = topological_sort(updates[i], rules);
      ans += corrected_update[corrected_update.size() / 2];
    }
  }

  cout << ans;
  return 0;
}
