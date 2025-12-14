
#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;

bool isInvalid(long long num) {
  string s = to_string(num);
  int n = s.size();

  for (int len = 1; len <= n / 2; len++) {
    if (n % len != 0)
      continue;
    int k = n / len;
    if (k < 2)
      continue;

    string block = s.substr(0, len);
    bool all_match = true;
    for (int j = 1; j < k; j++) {
      if (s.substr(j * len, len) != block) {
        all_match = false;
        break;
      }
    }
    if (all_match)
      return true;
  }

  return false;
}

int main(int argc, char *argv[]) {
  string data;
  char dash;
  long long start_range, end_range, ans = 0;
  ifstream myFile("data.txt");

  getline(myFile, data);
  string token;
  stringstream ss(data);

  while (getline(ss, token, ',')) {
    istringstream iss(token);
    iss >> start_range >> dash >> end_range;

    for (long long i = start_range; i <= end_range; i++) {
      if (isInvalid(i)) {
        ans += i;
      }
    }
  }

  cout << ans << endl;
  myFile.close();
  return 0;
}
