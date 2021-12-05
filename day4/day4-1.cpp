#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Matrix.h"
using namespace std;

int main() {
  freopen("input_2", "r", stdin);
  string line;
  vector<int> numbers;
  
  stringstream ss;
  ss.clear();

  // First input all numbers
  getline(cin, line);
  ss.str(line);
  for (int i; ss >> i;) {
    numbers.push_back(i);
    if (ss.peek() == ',')
      ss.ignore();
  }
  ss.clear();

  // Now input all matrices
  vector<Matrix> matrices;
  int temp;

  while(getline(cin, line)) {
    Matrix M1;
    for (int row=0; row<5; row++) {
      getline(cin, line);
      ss.str(line);
      for (int col=0; col<5; col++) {
        ss >> temp;
        M1.insertNum(temp, row, col);
      }
      ss.clear();
    }

    matrices.push_back(M1);
  }

  bool isFinished = false;
  // Matrix *finishedMatrix;
  vector<int> winners;
  for (auto num: numbers) {
    for (auto& m: matrices) {
      bool isWon = m.mark(num);
      if (isWon) {
        isFinished = isWon;
        int sum = m.getUnmarkedSum();
        int ans = (sum * num);
        winners.push_back(ans);
        cout << "Found a winner: " << ans << endl;
      }
    }
    if (isFinished) {
      break;
    }
  }
  
  auto maxElementIdx = max_element(winners.begin(), winners.end());

  cout << "Max: " << *maxElementIdx;
  
  return 0;
}