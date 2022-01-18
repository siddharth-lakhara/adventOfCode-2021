#pragma once

#include <vector>
#include <string>

class day9 {
public:
  day9();
	void PrintSolution1();
	void PrintSolution2();

private:
  const std::vector<std::string> Input;
  std::vector< std::vector<int> > heightMap;
  const int rowLength;
  int calculateSumOfRisks();
  int decodeNumAndFindSum();
};

