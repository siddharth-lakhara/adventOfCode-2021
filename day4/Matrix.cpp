#include "Matrix.h"
// #include <map>
// #include <vector>
#include <iostream>

using namespace std;

Matrix::Matrix() {}

void Matrix::insertNum(int num, int row, int col) {
  // cout << "Inserting: " << num << " " << row << " " << col << endl;
  struct mat_numbers matNum = {row, col, false};
  this->numbers[num] = matNum;
}

void Matrix::print() {
  cout << "Printing all numbers: " << endl;
  cout << "Map size: " << this->numbers.size() << endl; 
  for (auto itr = this->numbers.begin(); itr != this->numbers.end(); ++itr) {
    cout << "Number: " << itr->first << ", ";
    cout << "Row: " << itr->second.row << ", ";
    cout << "Col: " << itr->second.col << ", ";
    cout << "isMarked: " << itr->second.isMarked << endl;
  }

  cout << "Printing all strikes rows: " << endl;
  for (auto x: this->strikes[0]) {
    cout << x << " ";
  }
  cout << endl;

  cout << "Printing all strikes cols: " << endl;
  for (auto x: this->strikes[1]) {
    cout << x << " ";
  }
  cout << endl;
}

bool Matrix::mark(int num) {
  this->numbers[num].isMarked = true;
  int row_idx = this->numbers[num].row;
  int col_idx = this->numbers[num].col;

  this->strikes[0][row_idx]++;
  this->strikes[1][col_idx]++;

  if (this->strikes[0][row_idx] == 5 || this->strikes[1][col_idx] == 5) {
    return true;
  } else {
    return false;
  }
}

vector<int> Matrix::getUnmarkedNumbers() {
  vector<int> unmarkedNumbers;
  for (auto itr = this->numbers.begin(); itr != this->numbers.end(); itr++) {
    if (!(itr->second.isMarked)) {
      unmarkedNumbers.push_back(itr->first);
    }
  }
  return unmarkedNumbers;
}

int Matrix::getUnmarkedSum() {
  int sum = 0;
  vector<int> unmarkedSum = getUnmarkedNumbers();
  for (auto x: unmarkedSum) {
    sum+= x;
  }
  return sum;
};