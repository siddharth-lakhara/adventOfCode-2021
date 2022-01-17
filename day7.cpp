#include "day7.h"
#include "Utilities.h"
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

day7::day7()
	: Input(Utilities::ReadAllLinesInFile("day7-2.input"))
{}

void day7::PrintSolution1() {
  cout << calculateMinExpense(true) << endl;
}

void day7::PrintSolution2() {
  cout << calculateMinExpense(false) << endl;
}

int day7::calculateMinExpense(bool isFuelChangeConstant) {
  auto crabPositions = Utilities::ReadCommaSeparatedIntegers(Input[0]);

  int minFuelConsumption = INT32_MAX;
  int currentFuelConsumption = 0;
  int minPosition = *min_element(crabPositions.begin(), crabPositions.end());
  int maxPosition = *max_element(crabPositions.begin(), crabPositions.end());

  for (int finalPosition = minPosition; finalPosition<=maxPosition; finalPosition++) {
    currentFuelConsumption = 0;
    for (int crabPosition: crabPositions) {
      int stepsDiff = abs(crabPosition - finalPosition);
      if (isFuelChangeConstant) {
        currentFuelConsumption += stepsDiff;
      } else {
        currentFuelConsumption += (stepsDiff * (stepsDiff + 1)) / 2 ;
      }
    }

    minFuelConsumption = min(minFuelConsumption, currentFuelConsumption);
  }

  return minFuelConsumption;
}
