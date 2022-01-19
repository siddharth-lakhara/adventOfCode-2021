#include "day9.h"
#include "../Utilities.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

day9::day9()
	: Input(Utilities::ReadAllLinesInFile("day9/day9-2.input")), rowLength(Input[0].size())
{
  for (auto lines:Input) {
    vector<heightMapEle> row;
    for (char ch: lines) {
      int value = ch - '0';
      struct heightMapEle ele;
      ele.value = value;
      row.push_back(ele);
    }
    heightMap.push_back(row);
  }
  calculateLowPoints();
}

void day9::calculateLowPoints() {
  vector<int> results;
  for (int rowIdx=0; rowIdx<heightMap.size(); rowIdx++) {
    for (int colIdx=0; colIdx<rowLength; colIdx++) {
      int currElement = heightMap[rowIdx][colIdx].value;
      struct lowPointEle lowPoint;
      lowPoint.value = currElement;
      bool isLowUp = true; 
      bool isLowDown = true;
      bool isLowLeft = true;
      bool isLowRight = true;

      if (rowIdx-1>=0) {
        isLowUp = currElement<heightMap[rowIdx-1][colIdx].value;
      }
      if (rowIdx+1<heightMap.size()){
        isLowDown = currElement<heightMap[rowIdx+1][colIdx].value;
      }
      if (colIdx-1>=0) {
        isLowLeft = currElement<heightMap[rowIdx][colIdx-1].value;
      }
      if (colIdx+1<rowLength){
        isLowRight = currElement<heightMap[rowIdx][colIdx+1].value;
      }

      bool isLowPoint = isLowUp && isLowDown && isLowLeft && isLowRight;
      if (isLowPoint) {
        lowPoint.rowIdx = rowIdx;
        lowPoint.colIdx = colIdx;
        lowPoints.push_back(lowPoint);
      }
    }
  }
}

// 530
void day9::PrintSolution1() {
  cout << calculateSumOfRisks() << endl;
}

void day9::PrintSolution2() {
  calculateBasinSizes();
  Utilities::VerifyElseCrash(basinSizes.size() >= 3);
  int results = basinSizes[0] * basinSizes[1] * basinSizes[2];
  cout << results << endl;
}

int day9::calculateSumOfRisks() {
  int sum = 0;
  for (lowPointEle lowPoint: lowPoints) {
    sum += lowPoint.value + 1;
  }
  return sum;
}

void day9::calculateBasinSizes() {
  for (lowPointEle lowPoint: lowPoints) {
    int basinSize = findBasinSizeAt(lowPoint.rowIdx, lowPoint.colIdx);
    basinSizes.push_back(basinSize);
  }
  sort(basinSizes.begin(), basinSizes.end(), std::greater<>());
}

int day9::findBasinSizeAt(int rowIdx, int colIdx) {
  int basinSize = 1;
  int currElement = heightMap[rowIdx][colIdx].value;
  heightMap[rowIdx][colIdx].isPartOfBasin = true; // element is now a part of basin
  
  // Up
  if (rowIdx-1>=0) {
    int elementAbove = heightMap[rowIdx-1][colIdx].value;
    bool isElementVisited = heightMap[rowIdx-1][colIdx].isPartOfBasin;
    if (elementAbove!=9 && elementAbove>currElement && !isElementVisited) {
      basinSize += findBasinSizeAt(rowIdx-1, colIdx);
    }
  }

  // Down
  if (rowIdx+1<heightMap.size()) {
    int elementBelow = heightMap[rowIdx+1][colIdx].value;
    bool isElementVisited = heightMap[rowIdx+1][colIdx].isPartOfBasin;
    if (elementBelow!=9 && elementBelow>currElement && !isElementVisited) {
      basinSize += findBasinSizeAt(rowIdx+1, colIdx);
    }
  }

  // Left
  if (colIdx-1>=0) {
    int elementLeft = heightMap[rowIdx][colIdx-1].value;
    bool isElementVisited = heightMap[rowIdx][colIdx-1].isPartOfBasin;
    if (elementLeft!=9 && elementLeft>currElement && !isElementVisited) {
      basinSize += findBasinSizeAt(rowIdx, colIdx-1);
    }
  }

  // Right
  if (colIdx+1<rowLength) {
    int elementRight = heightMap[rowIdx][colIdx+1].value;
    bool isElementVisited = heightMap[rowIdx][colIdx+1].isPartOfBasin;
    if (elementRight!=9 && elementRight>currElement && !isElementVisited) {
      basinSize += findBasinSizeAt(rowIdx, colIdx+1);
    }
  }

  return basinSize;
}