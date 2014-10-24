// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1003_selection_sort.cpp: DataStructure2014@PanYan
// find the mininum number in unsorted numbers and push it at the back of
// sorted numbers
// http://soj.me/show_problem.php?pid=1003&cid=1405
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, arr[1000 + 10];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n - 1; i++) {
      int key = i;

      for (int j = i + 1; j < n; j++) {
        if (arr[key] > arr[j]) key = j;
      }

      if (key != i) {
        int temp = arr[key];
        arr[key] = arr[i];
        arr[i] = temp;
      }
      for (int k = 0; k < n; k++) {
        if (k) cout << ' ';
        cout << arr[k];
      }
      cout << endl;
    }

  }
  return 0;
}
