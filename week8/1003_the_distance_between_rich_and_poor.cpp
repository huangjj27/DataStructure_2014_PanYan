// Copyright (c) Junjie_Huang@SYSU(SNO:1331087). All Rights Reserved.
// week8/1003_the_distance_between_rich_and_poor.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1003&cid=1583
#include <iostream>
#include <algorithm>

#define max_size 100000+10

using std::cin;
using std::cout;
using std::endl;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    int data[max_size] = { 0 };
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> data[i];

    std::sort(data, data + n);
    int median1 = 0, median2 = 0;
    if (k % 2 == 0) {
      median1 = (data[k / 2] + data[k / 2 - 1]) / 2;
      median2 = (data[n - k / 2] + data[n - k / 2 - 1]) / 2;
    } else {
      median1 = data[(k - 1) / 2];
      median2 = data[n - (k - 1) / 2 - 1];
    }

    cout << median2 - median1 << endl;
  }

  return 0;
}
