// Copyright (c) Junjie_Huang@SYSU(SNO:13331087). All Rgights Reserved.
// week10/1003_TA_problem.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1003&cid=1618
#include <cstdio>

#define MAX_ROW 300
#define MAX_COL 10

int main() {
  int A = 0, B = 0;
  int i = 0, j = 0, matrix[MAX_ROW + 10][MAX_COL + 10] = { 0 };

  scanf("%d %d", &A, &B);
  while (scanf("%d %d", &i, &j) != EOF) matrix[i][j]++;

  for (int i = 1; i <= A; i++) {
    for (int j = 1; j <= B; j++) {
      if (j != 1) printf(" ");
      printf("%d", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
