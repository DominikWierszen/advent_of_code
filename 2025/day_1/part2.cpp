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
    for (int i = 0; i < distance; i++) {
      if (direction == 'R') {
        dial++;
      } else {
        dial--;
      }
      if ((dial % 100) == 0) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  myFile.close();
  return 0;
}
