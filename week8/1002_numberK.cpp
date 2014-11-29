// Copyright (c) Junjie_Huang@SYSU(SNO:1331087). All Rights Reserved.
// 1002_numberK.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1002&cid=1583
#include <cstdio>

#define MAX_SIZE 10000000

bool hash[2 * MAX_SIZE + 10] = { 0 };

int main() {
  int n = 0, k = 0, num = 0;
  scanf("%d %d", &n, &k);

  // build up a hash map
  for (int i = 0; i < n; i++) {
    scanf("%d", &num);
    hash[num + MAX_SIZE] = true;
  }

  // retrieve the hash map from the larger side.
  // |num| is the counter that we have found the |num|th largest number
  // |result| is the final answer that we want
  num = 0;
  int result = 0;
  for (int i = MAX_SIZE; i >= -MAX_SIZE && num <= MAX_SIZE; i--) {
    if (hash[i + MAX_SIZE]) num++;
    if (num == k) {
      result = i;
      break;
    }
  }

  printf("%d\n", result);
  return 0;
}
