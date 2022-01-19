#include "day0.h"
#include "../Utilities.h"
#include <iostream>
#include <vector>

using namespace std;

day0::day0()
	: Input(Utilities::ReadAllLinesInFile("day0/day0-1.input"))
{}

void day0::PrintSolution1() {
  cout << findPuzzleSolution() << endl;
}

void day0::PrintSolution2() {
  cout << findPuzzleSolution() << endl;
}

int day0::findPuzzleSolution() {
  return 0;
}