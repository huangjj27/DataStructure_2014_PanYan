// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week9/1000_mid_wave.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1000&cid=1602
#include <iostream>
#include <algorithm>

#define max_size 10

using std::cin;
using std::cout;
using std::endl;

int main() {
  int n, data[max_size] = { 0 };
  cin >> n;
  for (int i = 0; i < n; i++) cin >> data[i];

  std::sort(data, data + n);

  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << data[i];
  }
  cout << endl;

  if (n % 2)
    cout << data[n / 2];
  else
    cout << (data[n / 2] + data[n / 2 - 1]) / 2;

  return 0;
}
