#include <iostream>
#include <string>
#include <sstream>
#include<vector>
using namespace std;

int main() {
  freopen("input", "r", stdin);
  stringstream ss;
  ss.clear();
  string line;

  vector<int> inputs;
  int temp;

  while (getline(cin, line)) {
    ss.str(line);
    ss >> temp;

    inputs.push_back(temp);

    ss.clear();
  }

  int prev_window_sum = INT_MAX;
  int curr_window_sum = 0;
  int ans = 0;

  for (int i=0; i<=inputs.size()-3; i++) {
    curr_window_sum = inputs[i] + inputs[i+1] + inputs[i+2];
    if(curr_window_sum > prev_window_sum) {
      ans++;
    }
    prev_window_sum = curr_window_sum;
  }

  cout << ans;
  return 0;
}