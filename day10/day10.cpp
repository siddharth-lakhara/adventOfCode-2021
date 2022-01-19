#include "day10.h"
#include "../Utilities.h"
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

day10::day10()
	: Input(Utilities::ReadAllLinesInFile("day10/day10-2.input"))
{}

// 392043
void day10::PrintSolution1() {
  cout << findCorruptedLinesScore() << endl;
}

// 1605968119
void day10::PrintSolution2() {
  cout << findAutocompleteScore() << endl;
}

int day10::findCorruptedLinesScore() {
  uint64_t score = 0;
  int lineIdx = -1;
  for (string line: Input) {
    ++lineIdx;
    stack<char> charStack;
    for (char ch: line) {
      bool isOpeningChar = openingCharMap.find(ch) != openingCharMap.end();
      if (isOpeningChar) {
        charStack.push(ch);
      } else {
        char openingChar = charStack.top();
        char expectedClosingChar = openingCharMap.find(openingChar) -> second;
        if (ch != expectedClosingChar) {
          score += corruptedCharScores.find(ch) -> second;
          corruptedLinesIdx.insert(lineIdx);
          break;
        } else {
          charStack.pop();
        }
      }
    }
  }
  return score;
}

uint64_t day10::findAutocompleteScore() {
  multiset<uint64_t> scores;
  for (int lineIdx=0; lineIdx<Input.size(); lineIdx++) {
    uint64_t score = 0;
    bool isCorruptedLine = corruptedLinesIdx.find(lineIdx) != corruptedLinesIdx.end();
    // skip corrupted lines
    if (isCorruptedLine) {
      continue;
    }
    stack<char> charStack;
    string line = Input[lineIdx];
    for (char ch: line) {
      bool isOpeningChar = openingCharMap.find(ch) != openingCharMap.end();
      if (isOpeningChar) {
        charStack.push(ch);
      } else {
        charStack.pop();
      }
    }

    while (!charStack.empty()) {
      char openingChar = charStack.top();
      char charToAdd = openingCharMap.find(openingChar) -> second;
      int charScore = autocompleteCharScores.find(charToAdd) -> second;
      score = score*5 + (uint64_t)charScore;
      charStack.pop();
    }

    scores.insert(score);
  }

  // Get middle elements
  auto it = scores.begin();
  advance(it, scores.size()/2);
  
  return *it;
}