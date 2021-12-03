#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> calcMostCommonBitCounter(vector<string>& input, int size, int idx) {
  int counter_most_common_bit_0 = 0;
  int counter_most_common_bit_1 = 0;

  for (int i=0; i<input.size(); i++) {
    if (input[i][idx] == '0') {
      counter_most_common_bit_0++;
    } else {
      counter_most_common_bit_1++;
    }
  }

  return {counter_most_common_bit_0, counter_most_common_bit_1};
}

void deleteEntries(vector<string>& input, vector<int>& most_common_bit_counters, char defaultValue, int idx) {
  char most_common_bit;
  if (most_common_bit_counters[0] == most_common_bit_counters[1]) {
    most_common_bit = defaultValue;
  } else if (most_common_bit_counters[0] > most_common_bit_counters[1]) {
    most_common_bit = '0';
  } else {
    most_common_bit = '1';
  }

  for (int i=0; i<input.size(); i++) {
    if (input[i][idx] != most_common_bit) {
      input.erase(input.begin() + i);
      i--;
    }
  }
  
  return ;
}

int bin2dec(string str) {
  int ans = 0;
  int size = str.size();
  for (int i=0; i<size; i++) {
    if (str[i] == '1') {
      ans += pow(2, size-i-1);
    }
  }
  return ans;
}

int main() {
  freopen("input", "r", stdin);
  string line;

  vector<string> original_input;
  vector<string> input_o2;
  vector<string> input_co2;

  int temp_int;
  while (getline(cin, line)) {
    original_input.push_back(line);
    input_o2.push_back(line);
    input_co2.push_back(line);
  }

  int size = original_input[0].size();
  
  int counter = 0;
  while (input_o2.size() > 1 && counter < size) {
    vector<int> most_common_bit_counters = calcMostCommonBitCounter(input_o2, size, counter);
    deleteEntries(input_o2, most_common_bit_counters, '1', counter);
    counter++;
  }

  counter = 0;
  while (input_co2.size() > 1 && counter < size) {
    vector<int> most_common_bit_counters = calcMostCommonBitCounter(input_co2, size, counter);
    
    most_common_bit_counters[0] = input_co2.size() - most_common_bit_counters[0];
    most_common_bit_counters[1] = input_co2.size() - most_common_bit_counters[1];
    deleteEntries(input_co2, most_common_bit_counters, '0', counter);
    counter++;
  }

  int o2Rating = bin2dec(input_o2[0]);
  int co2Rating = bin2dec(input_co2[0]);
  cout << o2Rating * co2Rating ;

  return 0;
}