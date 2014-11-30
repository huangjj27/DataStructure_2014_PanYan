// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week9/1004_max_k_numbers.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1004&cid=1602
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_SIZE 10000

bool compare(int a, int b) { return a > b; }

void print(int arr[], int size) {
  // outputs a array
  for (int i = 0; i < size; i++) {
    if (i) printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main() {
  int N, K, data[MAX_SIZE+10];

  // whether a testcase is scaned
  while (scanf("%d %d", &N, &K) != EOF) {
    memset(data, 0, sizeof(data));

    for (int i = 0; i < K; i++) scanf("%d", &data[i]);
    std::sort(data, data + K, compare);

    print(data, K);
  }

  return 0;  // end main
}
