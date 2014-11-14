// Copyright (c) 2014 by Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week6/1002_eight_queens.cpp:DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1002&cid=1550
#include <cstdio>

#define MAX_SIZE 8  // the number of queens we need to push

// global varible arrays to storge the message we need to deal with.
// @Variable |row[]|: store which columns the queen is in exact row.
// @Variable |col[]|: whether a queen can be put in the exact column,
//   1's mean confilct while 0's mean possible.
// @Variable |diagonal[]|: whether a queen can be put in the exact diagonal
//  line.
// @Variable |back_diagonal[]|: whether a queen can be put in the exact
//   back diagonal line.
int row[MAX_SIZE + 1] = { 0 },
col[MAX_SIZE + 1] = { 0 },
diagonal[2 * MAX_SIZE + 1] = { 0 },
back_diagonal[2 * MAX_SIZE + 1] = { 0 };

void DFS_queens(int count = 0) {
  // Pre: a parameter |count| stands for the queens we has put on the keyborad.
  // When we call the function from outside, we think that we put queens from
  // the beginning, and we initailize |count| to zero.
  // Post: we output the result when we have all ready put all queens. Here
  // we decide to print the columns' order with the ith queen in as the output
  // method.
  // Usages: auto runs. We even needn't to initialize the |count|.

  // |count| being equal to |MAX_SIZE| means all of the 8 queens put in the
  // chessboard. Outputs the sequence of |row[]|. Otherwise puts another queen
  // in the next row.
  if (count == MAX_SIZE) {
    for (int i = 1; i <= MAX_SIZE; i++) {
      if (i) printf(" ");
      printf("%d", row[i]);
    }
    printf("\n");
  } else {
    count++;

    // when puts a queen, shows that anther queen can't be put in the current
    // column, diagonal line and back-diagonal line for the next steps.
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
  // Pre: none
  // Post: sequences of the chessboards with 8 queens that would never kill
  // one another queen.
  // Usages: auto runs.
  DFS_queens();
  return 0;
}
