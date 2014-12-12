// Copyright (c) Junjie_Huang@SYSU(SNO:13331087). All Rgights Reserved.
// 1000_sicily_1935.cpp: http://soj.sysu.edu.cn/1935
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>

#define MAX_SIZE 1000
#define STRING_SIZE 50

using std::cin;

using std::string;
using std::queue;

void rebuild(char tree[], string pre, string mid, int index = 0) {
  int left = 2 * index + 1, right = 2 * index + 2;
  if (pre.length()) {
    tree[index] = pre[0];
    int temp = mid.find(pre[0]);
    rebuild(tree, pre.substr(1, temp), mid.substr(0, temp), left);
    rebuild(tree, pre.substr(temp + 1), mid.substr(temp + 1), right);
  }
}

void BFS_visit(char tree[]) {
  for (int i = 0; i < MAX_SIZE; i++) {
    if (tree[i]) printf("%c", tree[i]);
  }
  printf("\n");
}

int main() {
  int n = 0;
  char tree[MAX_SIZE + 10];

  for (scanf("%d", &n); n; n--) {
    memset(tree, 0, sizeof(tree));
    string pre_order, mid_order;

    cin >> pre_order >> mid_order;
    rebuild(tree, pre_order, mid_order);

    BFS_visit(tree);
  }

  return 0;
}
