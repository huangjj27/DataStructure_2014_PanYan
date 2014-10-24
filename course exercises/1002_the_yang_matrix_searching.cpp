// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1002_the_yang_matrix_searching.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1002&cid=1405
#include <stdio.h>

int main() {
  int T;
  int n, k, data[1000 + 5][1000 + 5];
  int num, j = n - 1, i = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &data[i][j]);

    while (k--) {
      scanf("%d", &num);
      j = n - 1, i = 0;
      while (true) {
        if (num == data[i][j]) {
          printf("true\n");
          break;
        } else if (num > data[i][j] && i < n - 1) {
          i++;
        } else if (num < data[i][j] && j > 0) {
          j--;
        } else {
          printf("false\n");
          break;
        }
      }
    }
  }

  return 0;
}
