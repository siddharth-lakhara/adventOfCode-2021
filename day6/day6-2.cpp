#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <numeric>
using namespace std;

int main() {
  freopen("input2", "r", stdin);
  string line;
  stringstream ss;
  ss.clear();

  getline(cin, line);
  ss.str(line);

  vector<int> fishes;
  for (int i; ss >> i; ) { 
    fishes.push_back(i);
    if (ss.peek() == ',') {
      ss.ignore();
    }
  }

  constexpr int daysInCycle = 9;
  int totalDays = 256;

  array<u_int64_t, daysInCycle> currentFishes{};
  for (int daysRemaining: fishes) {
    ++currentFishes[daysRemaining];
  }

  for (int day=0; day<totalDays; day++) {
    // cout << "Running: "<< day << endl;
    array<u_int64_t, daysInCycle> newFishes{};
    newFishes[6] = currentFishes[0];
    newFishes[8] = currentFishes[0];
    for (int j=1; j<currentFishes.size(); j++) {
      newFishes[j-1] += currentFishes[j];
    }
    currentFishes = newFishes;
  }

  // for (auto f: currentFishes) {
  //   cout << f << endl;
  // }

  u_int64_t init = 0;
  auto answer = std::accumulate(currentFishes.begin(), currentFishes.end(), init);
  cout << answer << endl;

  return 0;
}