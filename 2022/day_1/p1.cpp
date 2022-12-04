#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int answer = 0;
  int calories;
  vector<int> data;
  ifstream myFile;
  myFile.open("data.txt");
  while (cin >> calories) {
    if ()
      data.push_back(calories);
  }

  for (auto x : data) {
    cout << x;
  }
  myFile.close();
  cout << answer;
  return 0;
}
