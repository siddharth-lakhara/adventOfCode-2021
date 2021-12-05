#include <map>
#include <vector>
#include <iostream>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H

struct mat_numbers {
  int row;
  int col;
  bool isMarked;
};

class Matrix {
  map<int, mat_numbers> numbers;
  vector<vector<int>> strikes {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };

  vector<int> getUnmarkedNumbers();

public:
  Matrix();
  bool mark(int num);
  int getUnmarkedSum();

  // Test
  void print();
  void insertNum(int num, int row, int col);
};

#endif