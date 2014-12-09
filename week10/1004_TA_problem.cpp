// Copyright (c) Junjie_Huang@SYSU(SNO:13331087). All Rgights Reserved.
// week10/1004_TA_problem.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1004&cid=1618
#include <cstdio>
#include <utility>

#define MAX_ROW 300
#define MAX_COL 10

using std::pair;

int main() {
  int A = 0, B = 0;
  int i = 0, j = 0, T = 0;
  pair<int, int> matrix[MAX_ROW + 10][MAX_COL + 10];

  scanf("%d %d", &A, &B);
  while (scanf("%d %d %d", &i, &j, &T) != EOF) {
    if (T)
      matrix[i][j].first++;
    else
      matrix[i][j].second++;
  }

  for (int i = 1; i <= A; i++) {
    for (int j = 1; j <= B; j++) {
      if (j != 1) printf(" ");
      printf("%d %d", matrix[i][j].first, matrix[i][j].second);
    }
    printf("\n");
  }

  return 0;
}
