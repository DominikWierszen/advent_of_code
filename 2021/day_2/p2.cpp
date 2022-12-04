#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifile;
  ifile.open("data.txt");
  string direction;
  int h_pos = 0, depth = 0, amount, aim = 0;
  vector<string> directions;
  vector<int> amounts;
  while (ifile >> direction >> amount) {
    directions.push_back(direction);
    amounts.push_back(amount);
  }

  for (int i = 0; i < directions.size(); i++) {
    if (directions[i] == "forward") {
      h_pos += amounts[i];
      depth += aim * amounts[i];
    } else if (directions[i] == "up") {
      aim -= amounts[i];
    } else if (directions[i] == "down") {
      aim += amounts[i];
    }
  }

  ifile.close();
  int answer = depth * h_pos;
  cout << answer;
  return 0;
}
