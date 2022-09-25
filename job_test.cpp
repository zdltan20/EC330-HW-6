#include "job.h"
#include <iostream>
//#include <vector>

using namespace std;
typedef vector<pair<int, int>> deplist;
#define getName(var)  #var

void print(deplist myList) {
	cout << endl;
	printf("%s", getName(myList));
	cout << endl;
	for(int i = 0; i < myList.size(); i++)
		cout << "{" << myList[i].first << ", " << myList[i].second << "}" << endl;
	cout << endl;
}

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

  cout << "canFinish 'ex1'? " << canFinish(2, ex1) << endl;
  cout << "canFinish 'ex2'? " << canFinish(2, ex2) << endl;
  cout << "canFinish 'circle'? " << canFinish(9, circle) << endl;
  cout << "canFinish 'line'? " << canFinish(10, line) << endl;
  cout << "canFinish 'star1'? " << canFinish(10, star1) << endl;
  cout << "canFinish 'star2'? " << canFinish(10, star2) << endl;
  cout << "canFinish 'tree'? " << canFinish(19, tree) << endl;
  
  cout << "canRun 'ex1' job 2 in slot 1? " << canRun(2, ex1, 2, 1) << endl;
  cout << "canRun 'line' job 1 in slot 1? " << canRun(10, line, 1, 1) << endl;
  cout << "canRun 'line' job 2 in slot 1? " << canRun(10, line, 2, 1) << endl;
  cout << "canRun 'line' job 5 in slot 10? " << canRun(10, line, 5, 10) << endl;
  cout << "canRun 'tree' job 5 in slot 3? " << canRun(19, tree, 5, 3) << endl;
  cout << "canRun 'tree' job 5 in slot 2? " << canRun(19, tree, 5, 2) << endl;
  //print(line);
  //print(tree);
  
  deplist circline;
  circline = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 1}, {13, 14}, {14, 15}, {15, 16}, {16, 17}, {17, 18}, {18, 19}, {19, 20}, {20, 21}, {21, 22}};
  cout << endl << "canFinish 'circline'? " << canFinish(22, circline) << endl;
  print(circline);
}
