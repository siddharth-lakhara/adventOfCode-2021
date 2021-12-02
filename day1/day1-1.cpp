#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  freopen("input", "r", stdin);
  stringstream ss;
  ss.clear();
  string line;

  int prev_num = INT_MAX;
  int curr_num;
  int ans = 0;

  while (getline(cin, line)) {
    ss.str(line);
    ss >> curr_num;

    if (curr_num > prev_num) {
      ans++;
    }
    prev_num = curr_num;

    ss.clear();
  }

  cout << ans;

  return 0;
}