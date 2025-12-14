#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string data;
  int a, b;
  ifstream myFile;
  myFile.open("data.txt");
  while (getline(myFile, data)) {
    istringstream iss(data);
    iss >> a >> b;
  }

  cout << a << endl;
  myFile.close();
  return 0;
}
