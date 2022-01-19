#pragma once

#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class day10 {
public:
  day10();
	void PrintSolution1();
	void PrintSolution2();

private:
  const std::vector<std::string> Input;
  const map<char, uint32_t> corruptedCharScores = {
    {')', 3},
    {']', 57},
    {'}', 1197},
    {'>', 25137}
  };
  const map<char, char> openingCharMap = {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'},
    {'<', '>'}
  };
  const map<char, uint32_t> autocompleteCharScores = {
    {')', 1},
    {']', 2},
    {'}', 3},
    {'>', 4}
  };
  multiset<int> corruptedLinesIdx;
  
  int findCorruptedLinesScore();
  uint64_t findAutocompleteScore();
};

