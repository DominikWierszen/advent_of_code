#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string data;
  char direction;
  int dial = 50, ans = 0, distance;
  ifstream myFile;
  myFile.open("data.txt");
  while (getline(myFile, data)) {
    istringstream iss(data);
    iss >> direction >> distance;
    // left.push_back(num1);
    if (direction == 'R') {
      dial = (dial + distance) % 100;
    } else {
      dial = (dial - distance) % 100;
    }
    if (dial == 0)
      ans++;
  }
  // sort(left.begin(), left.end());

  cout << ans << endl;

  myFile.close();
  return 0;
}
