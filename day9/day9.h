#pragma once

#include <vector>
#include <string>

struct heightMapEle {
  int value;
  bool isPartOfBasin = false;
};

struct lowPointEle {
  int value;
  int rowIdx;
  int colIdx;
};

class day9 {
public:
  day9();
	void PrintSolution1();
	void PrintSolution2();

private:
  const std::vector<std::string> Input;
  std::vector< std::vector<heightMapEle> > heightMap;
  const int rowLength;
  std::vector<lowPointEle> lowPoints;
  std::vector<int> basinSizes;
  
  int calculateSumOfRisks();
  void calculateLowPoints();
  void calculateBasinSizes();
  int findBasinSizeAt(int rowIdx, int colIdx);
};

