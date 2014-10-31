// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week5/1001_maze_DFS.cpp: DataStructure2014@PanYan
// http://soj.me/contest_detail.php?cid=1523
// Depth-First-Search algorithm practice
#include <iostream>
#include <list>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::list;
using std::pair;

#define MAX_SIZE 10  // max size of the maze

int maze[MAX_SIZE + 1][MAX_SIZE + 1];

list< pair<int, int> > DFS(int m, int n) {
  int x = 0, y = 0;
  list< pair<int, int> > path;
  while (x < m && y < n) {
    // the searching order is up, down, left, and right
    if (x == m - 1 && y == n - 1) {
      path.push_back(pair<int, int>(x, y));
      break;
    }  // finds a path and needn't search anymore
    if (maze[x - 1][y] != 1 && x - 1 >= 0) {
      path.push_back(pair<int, int>(x, y));
      maze[x][y] = 1;
      x--;
    } else if (maze[x + 1][y] != 1 && (x + 1 <= m - 1)) {
      path.push_back(pair<int, int>(x, y));
      maze[x][y] = 1;
      x++;
    } else if((maze[x][y - 1] != 1 && y - 1 >= 0)) {
      path.push_back(pair<int, int>(x, y));
      maze[x][y] = 1;
      y--;
    } else if (maze[x][y + 1] != 1 && (y + 1 <= n - 1)) {
        path.push_back(pair<int, int>(x, y));
        maze[x][y] = 1;
        y++;
    } else {
      // when we don't find a path, we turn backwords
      // and mark out where we have searched
      if (!path.empty()) {
        maze[x][y] = 1;
        x = path.back().first;
        y = path.back().second;
        path.pop_back();
        maze[x][y] = 0;
      } else {
        break;
      }
    }
  }
  return path;
}

int main() {
  int test_cases;
  for (cin >> test_cases; test_cases; test_cases--) {
    memset(maze, 0, sizeof(maze));
    int m, n;
    cin >> m >> n;

    // input the maze
    for (int x = 0; x < m; x++) {
      string line;
      cin >> line;  // notice that there is no space between elements

      for (int y = 0; y < n; y++) {
        maze[x][y] = line[y] - '0';
      }
    }

    list< pair<int, int> > path = DFS(m, n);  // get a path

    if (!path.empty()) {
      for (list< pair<int, int> >::iterator it = path.begin();
           it != path.end(); it++) {
        if (it != path.begin()) cout << " ";
        cout << "(" << it->first << "," << it->second << ")";
      }
      cout << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}
