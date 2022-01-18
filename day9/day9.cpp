#include "day9.h"
#include "../Utilities.h"
#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <limits>
#include <algorithm>

using namespace std;

day9::day9()
	: Input(Utilities::ReadAllLinesInFile("day9/day9-1.input")), rowLength(Input[0].size())
{
  for (auto lines:Input) {

  }
  cout << "Input initialised: " << Input.size() << " " << rowLength << endl;
}

void day9::PrintSolution1() {
  cout << calculateSumOfRisks() << endl;
}

void day9::PrintSolution2() {
  cout << decodeNumAndFindSum() << endl;
}

int day9::calculateSumOfRisks() {
  return -1;
}

// Gives wrong answer. Abandoned
int day9::decodeNumAndFindSum() {
  return -1;
}