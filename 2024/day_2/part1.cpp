#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string data;
  int num, ans;
  ifstream myFile;
  myFile.open("data.txt");
  while (getline(myFile, data)) {
    istringstream iss(data);
    int temp = -1;
    while (iss >> num) {
      int prev;
      if (prev != -1) {
        if (num > prev && num - prev > 3) {
        }
      } else {
        prev = num;
      }
    }
  }

  myFile.close();
  return 0;
}
