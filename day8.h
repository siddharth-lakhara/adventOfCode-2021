#pragma once

#include <vector>
#include <string>

class day8 {
public:
  day8();
	void PrintSolution1();
	void PrintSolution2();

private:
  const std::vector<std::string> Input;
  int findUniqueNumFrequency();
  int decodeNumAndFindSum();
};

