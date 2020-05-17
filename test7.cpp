#include "job.h"
#include <iostream>
#include <vector>

using namespace std;
typedef vector<pair<int, int>> deplist;

int main() {
  deplist ex1, ex2, circle, line, star1, star2, tree;
  ex1 = {{1, 2}};
  ex2 = {{1, 2}, {2, 1}};
  for (int i = 1; i < 10; i++) {
    circle.push_back({i, (i + 1) % 10});
    line.push_back({i, i + 1});
    star1.push_back({10, i});
    star2.push_back({i, 10});
    tree.push_back({i, 0 + (i << 1)});
    tree.push_back({i, 1 + (i << 1)});
  }

  
  circle.pop_back();
  circle.push_back({9, 1});

  cout << "ex1: " << endl; 
  for (int i = 0; i < ex1.size(); i++) {
    cout  << "f: " << ex1[i].first << " " << "s: " << ex1[i].second << " ";
  }

  cout << endl;

    cout << "ex2: " << endl; 
  for (int i = 0; i < ex2.size(); i++) {
    cout  << "f: "  << ex2[i].first << " " << "s: " << ex2[i].second << " ";
  }

  cout << endl;

    cout << "circle: " << endl;
  for (int i = 0; i < circle.size(); i++) {
    cout  << "f: " << circle[i].first << " " << "s: " << circle[i].second << " ";
  }

  cout << endl;

    cout << "line: " << endl;
  for (int i = 0; i < line.size(); i++) {
    cout <<  "f: " << line[i].first << " " << "s: " << line[i].second << " ";
  }

  cout << endl;

    cout << "star1: " << endl;
  for (int i = 0; i < star1.size(); i++) {
    cout << "f: " << star1[i].first << " " << "s: " << star1[i].second << " ";
  }

  cout << endl;

    cout << "star2: " << endl;
  for (int i = 0; i < star2.size(); i++) {
    cout << "f: " << star2[i].first << " " << "s: " << star2[i].second << " ";
  }

    cout << endl;

deplist weurd_shit = { { 2, 1 }, {3, 1}, {3, 2}, {4, 1}, {4, 2}, {4, 3}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {7, 1}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {7, 6}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {8, 6}, {8, 7}, {9, 1}, {9, 2}, {9, 3}, {9, 4}, {9, 5}, {9, 6}, {9, 7}, {9, 8}, {10, 1}, {10, 2}, {10, 3}, {10, 4}, {10, 5}, {10, 6}, {10, 7}, {10, 8}, {10, 9}, {11, 1}, {11, 2}, {11, 3}, {11, 4}, {11, 5}, {11, 6}, {11, 7},
{11, 8}, {11, 9}, {11, 10}, {12, 1}, {12, 2}, {12, 3}, {12, 4}, {12, 5}, {12, 6}, {12, 7}, {12, 8}, {12, 9}, {12, 10}, {12, 11}, {13, 1}, {13, 2}, {13, 3}, {13, 4}, {13, 5}, {13, 6}, {13, 7}, {13, 8}, {13, 9}, {13, 10}, {13, 11}, {13, 12}, {14, 1}, {14, 2}, {14, 3}, {14, 4}, {14, 5}, {14, 6}, {14, 7}, {14, 8}, {14, 9}, {14, 10}, {14, 11}, {14, 12}, {14, 13}, {15, 1}, {15, 2}, {15, 3}, {15, 4}, {15, 5}, {15, 6}, {15, 7}, {15, 8}, {15, 9}, {15, 10}, {15, 11}, {15, 12}, {15, 13}, {15, 14}, {16, 1}, {16, 2}, {16, 3}, {16, 4}, {16, 5}, {16, 6}, {16, 7}, {16, 8}, {16, 9}, {16, 10}, {16, 11}, {16, 12}, {16, 13}, {16, 14}, {16, 15}, {17, 1}, {17, 2}, {17, 3}, {17, 4}, {17, 5}, {17, 6}, {17, 7}, {17, 8}, {17, 9}, {17, 10}, {17, 11}, {17, 12}, {17, 13}, {17, 14}, {17, 15}, {17, 16}, {18, 1}, {18, 2}, {18, 3}, {18, 4}, {18, 5}, {18, 6}, {18, 7}, {18, 8}, {18, 9}, {18, 10}, {18, 11}, {18, 12}, {18, 13}, {18, 14}, {18, 15}, {18, 16}, {18, 17}, {19, 1}, {19, 2}, {19, 3}, {19, 4}, {19, 5}, {19, 6}, {19, 7}, {19, 8}, {19, 9}, {19, 10}, {19, 11}, {19, 12}, {19, 13}, {19, 14}, {19, 15}, {19, 16}, {19, 17}, {19, 18}, {20, 1}, {20, 2}, {20, 3}, {20, 4}, {20, 5}, {20, 6}, {20, 7}, {20, 8}, {20, 9}, {20, 10}, {20, 11}, {20, 12}, {20, 13}, {20, 14}, {20, 15}, {20, 16}, {20, 17}, {20, 18}, {20, 19} };

  cout<< "x " << canRun(20, weurd_shit, 18, 18) << endl;

  cout << "canFinish 'ex1'? " << endl << canFinish(2, ex1) << endl;
  cout << "canFinish 'ex2'? " << endl << canFinish(2, ex2) << endl;
  cout << "canFinish 'circle'? " << endl << canFinish(9, circle) << endl;
  cout << "canFinish 'line'? " << endl << canFinish(10, line) << endl;
  cout << "canFinish 'star1'? " << endl << canFinish(10, star1) << endl;
  cout << "canFinish 'star2'? " << endl << canFinish(10, star2) << endl;
  cout << "canFinish 'tree'? " << endl << canFinish(19, tree) << endl;
  cout << "canRun 'ex1' job 2 in slot 1? " << endl << canRun(2, ex1, 2, 1) << endl;
  cout << "canRun 'line' job 1 in slot 1? " << endl << canRun(10, line, 1, 1) << endl;
  cout << "canRun 'line' job 2 in slot 1? " << endl << canRun(10, line, 2, 1) << endl;
  cout << "canRun 'line' job 5 in slot 10? " << endl << canRun(10, line, 5, 10) << endl;
  cout << "canRun 'tree' job 5 in slot 3? " << endl << canRun(19, tree, 5, 3) << endl;
  cout << "canRun 'tree' job 5 in slot 2? " << endl << canRun(19, tree, 5, 2) << endl;
}