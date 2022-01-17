#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  freopen("input2", "r", stdin);
  string line;
  stringstream ss;
  ss.clear();

  getline(cin, line);
  ss.str(line);

  vector<int> numbers;
  for (int i; ss >> i; ) {
    numbers.push_back(i);
    if (ss.peek() == ',') {
      ss.ignore();
    }
  }

  int day_limit = 80;
  for (int day=0; day<day_limit; day++) {
    int originalSize = numbers.size();
    // cout << "Count on Day " << day << ": ";
    for (int idx=0; idx<originalSize; idx++) {
      // cout << numbers[idx] << " ";
      numbers[idx]--;
      if (numbers[idx] < 0) {
        numbers[idx] = 6;
        numbers.push_back(8);
      }
    }
    // cout << endl;
  }
  cout << "Ans: " << numbers.size();

  return 0;
}