#pragma once

#include <vector>
#include <string>

class day0 {
public:
  day0();
	void PrintSolution1();
	void PrintSolution2();

private:
  const std::vector<std::string> Input;
  int findPuzzleSolution();
};

