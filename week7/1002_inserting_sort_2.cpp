// Copyright (c) 2014 by Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1002_inserting_sort_2.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1002&cid=1567
#include <iostream>

#define max_size 10005

using std::cin;
using std::cout;
using std::endl;

bool isSorted(int data[], int size) {
  for (int i = 0; i < size - 1; i++) {
    if (data[i] > data[i + 1]) return false;
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int data[max_size] = { 0 };
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> data[i];

    int sum = 0;
    for (int i = 1; i < N; i++) {
      int temp = data[i];
      int j = i - 1;
      while (j >= 0 && data[j] > temp) {
        data[j + 1] = data[j];
        j--;
      }
      data[j + 1] = temp;
      if (j == i - 1)
        continue;
      else
        sum += 5;
    }
    cout << sum << endl;
  }
  return 0;
}
