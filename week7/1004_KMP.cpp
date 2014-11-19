// Copyright (c) Junjie_Huang@SYSU(SNO:1331087). All Rights Reserved.
// 1004_KMP.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1004&cid=1567
#include <cstdio>

#define MAX_SIZE 100000

int main() {
  long code_dimension = 0, protection_dimension = 0;
  int code[MAX_SIZE + 10], protection[MAX_SIZE + 10];
  long next[MAX_SIZE + 10] = { 0 };

  while (scanf("%ld", &code_dimension) != EOF) {
    for (long i = 0; i < code_dimension; i++)
      scanf("%d", &code[i]);

    next[0] = 0;
    for (long i = 1, j = 0; i < code_dimension; i++) {
      j = (code[j] == code[i - 1] ? j + 1 : 0);
      next[i] = j;
    }

    scanf("%ld", &protection_dimension);
    long j = 0, i = 0, result = 0;
    for (; i < protection_dimension; i++) {
      scanf("%d", &protection[i]);
      if (j != code_dimension) {
        j = code[j] == protection[i] ? j + 1 : next[j];
        if (j == code_dimension) result = i - j + 1;
      }
    }

    j == code_dimension ? printf("%d\n", result) : printf("no solution\n");
  }
  return 0;
}
