#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
  freopen("input2", "r", stdin);

  string line;
  stringstream ss;
  ss.clear();

  char uselessChars;
  int x1, y1, x2, y2;

  vector<vector<int>> pointCounter(1000, vector<int>(1000, 0));

  while(getline(cin, line)) {
    ss.str(line);
    
    ss >> x1;
    ss >> uselessChars;
    ss >> y1;

    ss >> uselessChars;
    ss >> uselessChars;

    ss >> x2;
    ss >> uselessChars;
    ss >> y2;

    bool isHorizontal = (y1 == y2);
    bool isVertical = (x1 == x2);

    if (isHorizontal || isVertical) {
      if (isHorizontal) {
        int row_idx = y1;
        int from = min(x1, x2);
        int to = max(x1, x2);
        
        for (int col_idx=from; col_idx<=to; col_idx++) {
          pointCounter[row_idx][col_idx]++;
        }
      } else {
        int col_idx = x1;
        int from = min(y1, y2);
        int to = max(y1, y2);
        
        for (int row_idx=from; row_idx<=to; row_idx++) {
          pointCounter[row_idx][col_idx]++;
        }
      }
    } else {
      // Diagonal lines
      int x_incr = (x1 < x2) ? 1 : -1;
      int y_incr = (y1 < y2) ? 1 : -1;

      int pX = x1;
      int pY = y1;
      for (;pX!=x2 && pY!=y2;) {
        pointCounter[pY][pX]++;
        pX += x_incr;
        pY += y_incr;
      }
      pointCounter[y2][x2]++;
    }
    
    ss.clear();
  }

  int counter = 0;
  for (auto r: pointCounter) {
    for (auto c: r) {
      // cout << c << " ";
      if (c >= 2) {
        counter++;
      }
    }
    // cout << endl;
  }

  cout << "Ans: " << counter << endl;
  return 0;
}