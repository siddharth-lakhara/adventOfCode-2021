#include "day8.h"
#include "Utilities.h"
#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <limits>
#include <algorithm>

using namespace std;

day8::day8()
	: Input(Utilities::ReadAllLinesInFile("day8-1.input"))
{}

void day8::PrintSolution1() {
  cout << findUniqueNumFrequency() << endl;
}

void day8::PrintSolution2() {
  cout << decodeNumAndFindSum() << endl;
}

int day8::findUniqueNumFrequency() {
  int requiredNumbersCount = 0;
  constexpr array<int, 4> requiredLengths = {2, 3, 4, 7}; 
  for (auto line: Input) {
    auto allOutputNumbers = Utilities::SplitString(line, "|");
    auto outputNumbers = Utilities::SplitString(allOutputNumbers[1], " ");

    // Remove first empty string
    outputNumbers.erase(outputNumbers.begin());

    for (auto outputNumber: outputNumbers) {
      auto lengthItr = find(requiredLengths.begin(), requiredLengths.end(), outputNumber.size());
      bool isRequiredNumber = lengthItr != requiredLengths.end();
      if (isRequiredNumber) {
        requiredNumbersCount++;
      }
    }
  }
  return requiredNumbersCount;
}

// Gives wrong answer. Abandoned
int day8::decodeNumAndFindSum() {
  map<string, string> outputNumberMap = {
    {"abcdeg", "0"},
    {"ab", "1"},
    {"acdfg", "2"},
    {"abcdf", "3"},
    {"abef", "4"},
    {"bcdef", "5"},
    {"bcdefg", "6"},
    {"abd", "7"},
    {"abcdefg", "8"},
    {"abcdef", "9"},
  };

  int sum = 0;

  for (auto line: Input) {
    auto allOutputNumbers = Utilities::SplitString(line, "|");
    auto outputNumbers = Utilities::SplitString(allOutputNumbers[1], " ");

    // Remove first empty string
    outputNumbers.erase(outputNumbers.begin());

    string resultStr = "";
    int resultNum = 0;
    for (auto outputNumber: outputNumbers) {
      sort(outputNumber.begin(), outputNumber.end());
      resultStr += outputNumberMap[outputNumber];
    }
    if (resultStr.size() >= 1) {
      resultNum = stoi(resultStr);
    }
    cout << resultStr << ", " << resultNum << endl;

    sum += resultNum;
  }
  return sum;
}