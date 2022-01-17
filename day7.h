#pragma once

#include <vector>
#include <string>

class day7 {
public:
  day7();
	void PrintSolution1();
	void PrintSolution2();

private:
  const std::vector<std::string> Input;
  int calculateMinExpense(bool isFuelChangeConstant);
};

