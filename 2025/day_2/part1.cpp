#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string data;
  char dash;
  long long start_range, end_range, ans = 0;
  ifstream myFile;
  myFile.open("data.txt");
  getline(myFile, data);

  string token;
  stringstream ss(data);

  while (getline(ss, token, ',')) {
    istringstream iss(token);
    iss >> start_range >> dash >> end_range;
    for (long long i = start_range; i <= end_range; i++) {
      string s = to_string(i);
      int n = s.size();
      if (n % 2 != 0)
        continue;
      string first_half = s.substr(0, n / 2);
      string second_half = s.substr(n / 2);

      if (first_half == second_half) {
        ans = ans + i;
      }
    }
  }

  cout << ans << endl;
  myFile.close();
  return 0;
}
