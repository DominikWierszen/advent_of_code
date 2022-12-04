#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int answer = 0;
  int calories;

  ifstream myFile;
  myFile.open("data.txt");

  myFile.close();
  cout << answer;
  return 0;
}
