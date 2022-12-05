#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  int max = 0;
  int current = 0;
  string calories;
  ifstream myFile;
  myFile.open("data.txt");
  while (getline(myFile, calories)) {
    if (calories.empty()) {
      if (max < current) {
        max = current;
      }
      current = 0;
    } else {
      current += stoi(calories);
    }
  }

  myFile.close();
  cout << max;
  return 0;
}
