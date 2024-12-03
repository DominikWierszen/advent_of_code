#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string data;
  vector<int> left, right;
  int num1, num2, ans;
  ifstream myFile;
  myFile.open("data.txt");
  while (getline(myFile, data)) {
    istringstream iss(data);
    iss >> num1 >> num2;
    left.push_back(num1);
    right.push_back(num2);
  }
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());
  for (int i = 0; i < left.size(); i++) {
    if (left[i] > right[i]) {
      ans += left[i] - right[i];
    } else {
      ans += right[i] - left[i];
    }
  }
  cout << ans;

  myFile.close();
  return 0;
}
