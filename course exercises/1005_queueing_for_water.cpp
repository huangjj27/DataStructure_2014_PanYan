// Copyright (c) Junjie_Huang@SYSU(SNO:1331087). All Rights Reserved.
// 1005_queueing_for_water.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1005&cid=1405
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#define max_size 1000+10
using std::cin;
using std::cout;
using std::endl;

typedef std::pair<int, int> Pair;
bool isLess(Pair a, Pair b) {
  if (a.second == b.second) {
    if (a.first < b.first)
      return true;
    else
      return false;
  }
  return a.second < b.second;
}

int main() {
  int n;
  std::vector<Pair> data;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    data.push_back(Pair(i, x));
  }

  std::sort(data.begin(), data.end(), isLess);

  std::vector<Pair>::iterator it = data.begin();
  int sum = 0;
  for (int i = 0; i < n; it++, i++) {
    sum += (it->second)*(n - i - 1);
    if (i) cout << " ";
    cout << it->first;
  }
  cout << endl;
  cout << std::fixed << std::setprecision(2)
    << (sum + 0.0) / (n + 0.0) << endl;

  return 0;
}
