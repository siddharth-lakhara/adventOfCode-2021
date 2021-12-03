#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  freopen("input", "r", stdin);
  string line;

  vector<string> input;

  int temp_int;
  while (getline(cin, line)) {
    input.push_back(line);
  }

  int size = input[0].size();
  vector<int> counter_most_common_bit_0(size, 0);
  vector<int> counter_most_common_bit_1(size, 0);

  int most_common_bit = 0;
  int least_common_bit = 0;

  for (int i=0; i<input.size(); i++) {
    for (int j=0; j<size; j++) {
      if (input[i][j] == '0') {
        counter_most_common_bit_0[j]++;
      } else {
        counter_most_common_bit_1[j]++;
      }
    }
  }

  for (int i=0; i<size; i++) {
    if (counter_most_common_bit_0[i] > counter_most_common_bit_1[i]) {
      least_common_bit += pow(2, size-i-1);
    } else {
      most_common_bit += pow(2, size-i-1);
    }
  }
  
  cout << most_common_bit*least_common_bit;
  
  
  return 0;
}