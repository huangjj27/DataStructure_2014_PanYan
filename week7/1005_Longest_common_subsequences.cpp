// Copyright (c) Junjie_Huang@SYSU(SNO:1331087). All Rights Reserved.
// 1005_Longest_common_subsequences.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1005&cid=1567
#include <cstdio>
#include <cstring>

#define MAX_SIZE 1000
#define row i+1
#define col j+1

#define max(b, c) (((b) > (c)) ? (b) : (c))

int LCS(char* str1, char* str2) {
  int common[MAX_SIZE + 10][MAX_SIZE + 10];
  for (int i = 0; i <= MAX_SIZE; i++)
    common[0][i] = common[i][0] = 0;

  int length1 = strlen(str1), length2 = strlen(str2);

  int i, j;
  for (i = 0; i < length1; i++) {
    for (j = 0; j < length2; j++) {
      common[row][col] = (str1[i] == str2[j]) ?
        common[row - 1][col - 1] + 1 :
        max(common[row - 1][col], common[row][col - 1]);
    }
  }
  return common[length1][length2];
}

int main() {
  char str1[MAX_SIZE + 1], str2[MAX_SIZE + 1];
  while (scanf("%s %s", &str1, &str2) != EOF)
    printf("%d\n", LCS(str1, str2));
  return 0;
}
