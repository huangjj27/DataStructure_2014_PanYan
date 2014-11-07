// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week6/1002_eight_queens.cpp:DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1002&cid=1550
#include <cstdio>

#define MAX_SIZE 8

int row[MAX_SIZE + 1] = { 0 },
col[MAX_SIZE + 1] = { 0 },
diagonal[2 * MAX_SIZE + 1] = { 0 },
back_diagonal[2 * MAX_SIZE + 1] = { 0 };

void DFS_queens(int count = 0) {
  if (count == MAX_SIZE) {
    for (int i = 1; i <= MAX_SIZE; i++) {
      if (i) printf(" ");
      printf("%d", row[i]);
    }
    printf("\n");
  } else {
    count++;
    for (int i = 1; i <= MAX_SIZE; i++) {
      if (!(col[i]
        || diagonal[MAX_SIZE + count - i]
        || back_diagonal[count + i - 1])) {
        row[count] = i;
        col[i] = diagonal[MAX_SIZE + count - i]
          = back_diagonal[count + i - 1]
          = 1;
        DFS_queens(count);
        col[i] = diagonal[MAX_SIZE + count - i]
          = back_diagonal[count + i - 1]
          = 0;
      }
    }
  }
}

int main() {
  DFS_queens();
  return 0;
}
