#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

int main(int argc, char *argv[]) {
  string data;
  vector<int> left;
  unordered_map<int, int> right;
  int num1, num2, ans;
  ifstream myFile;
  myFile.open("data.txt");
  while (getline(myFile, data)) {
    istringstream iss(data);
    iss >> num1 >> num2;
    left.push_back(num1);
    right[num2]++;
  }
  for (int i = 0; i < left.size(); i++) {
    auto it = right.find(left[i]);
    if (it != right.end()) { // Ensure the key exists in right
      ans += left[i] * it->second;
    }
  }
  cout << ans;

  myFile.close();
  return 0;
}
