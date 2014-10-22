// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1000_metro_planning.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1000&cid=1405
#include <iostream>
#include <cstring>

#define max_size 100
#define max_int 10000

using std::cin;
using std::cout;
using std::endl;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int map[max_size][max_int], low[max_size], visited[max_size] = { 0 };
    memset(map, max_int, sizeof(map));
    memset(low, max_int, sizeof(low));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> map[i][j];

    int pos = 0;
    for (int i = 0; i < n; i++)
    if (i != pos) low[i] = map[pos][i];
    visited[0] = 1;

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
      int min = max_int;
      for (int j = 0; j < n; j++) {
        if (!visited[j] && min > low[j]) {
          min = low[j];
          pos = j;
        }
      }
      sum += min;
      visited[pos] = 1;

      for (int i = 0; i < n; i++) {
        if (!visited[i] && low[i] > map[pos][i]) low[i] = map[pos][i];
      }
    }

    cout << sum << endl;
  }

  return 0;
}
