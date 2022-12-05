#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// A = Rock, B = Paper, C = Scissors
// X = Rock, Y = Paper, Z = Scissors
// Rock = 1 Paper = 2 Scossors = 3

int main(int argc, char *argv[]) {
  ifstream myFile;
  myFile.open("data.txt");
  char me, they;
  int score = 0;
  while (myFile >> they >> me) {

    if (they == 'A') {
      if (me == 'Y') {
        score += 8;
      } else if (me == 'X') {
        score += 4;
      } else if (me == 'Z') {
        score += 3;
      }
    } else if (they == 'B') {
      if (me == 'Y') {
        score += 5;
      } else if (me == 'X') {
        score += 1;
      } else if (me == 'Z') {
        score += 9;
      }
    } else if (they == 'C') {
      if (me == 'Y') {
        score += 2;
      } else if (me == 'X') {
        score += 7;
      } else if (me == 'Z') {
        score += 6;
      }
    }
  }

  myFile.close();
  cout << score;
  return 0;
}
