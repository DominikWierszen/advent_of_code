#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
// day1
int main(int argc, char *argv[]) {
  ifstream myFile;
  vector<int> data;
  myFile.open("data.txt");
  int lines = 0;
  int count = 0;
  while (myFile >> lines) {
    data.push_back(lines);
  }
  myFile.close();
  int previous = data[1];
  for (int i = 1; i < data.size(); i++) {
    if (data[i] + data[i + 1] + data[i + 2] >
        data[i - 1] + data[i] + data[i + 1]) {
      count++;
    }
  }

  cout << count;
  return 0;
}
