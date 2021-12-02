#include <iostream>
#include <string>
#include <sstream>
#include<vector>
using namespace std;

int main() {
  freopen("input", "r", stdin);
  stringstream ss;
  ss.clear();
  string line;

  vector<string> commands;
  string temp_string;

  vector<int> args;
  int temp_int;

  while (getline(cin, line)) {
    ss.str(line);
    ss >> temp_string;
    ss >> temp_int;

    commands.push_back(temp_string);
    args.push_back(temp_int);

    ss.clear();
  }

  int horizontalDistance = 0;
  int depth = 0;

  for (int i=0; i<=commands.size(); i++) {
    if (commands[i] == "forward") {
      horizontalDistance += args[i];
    } else if (commands[i] == "up") {
      depth -= args[i];
    } else {
      depth += args[i];
    }
  }

  cout << "Ans: " << horizontalDistance*depth << endl;
  return 0;
}