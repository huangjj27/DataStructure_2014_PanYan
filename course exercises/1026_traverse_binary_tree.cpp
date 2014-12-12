// Copyright (c) Junjie_Huang@SYSU(SNO:13331087). All Rgights Reserved.
// 1026_traverse_binary_tree.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1026&cid=1405
#include <cstdio>
#include <climits>
#include <cstring>

#define MAX_SIZE 3000

void pre_order(int tree[], int index = 0) {
  int left = 2 * index + 1, right = 2 * index + 2;
  if (tree[index] != INT_MAX) {
    printf("%d ", tree[index]);
    pre_order(tree, left);
    pre_order(tree, right);
  }
}

void mid_order(int tree[], int index = 0) {
  int left = 2 * index + 1, right = 2 * index + 2;
  if (tree[index] != INT_MAX) {
    mid_order(tree, left);
    printf("%d ", tree[index]);
    mid_order(tree, right);
  }
}

void insert(int tree[], int temp, int index = 0) {
  int left = 2 * index + 1, right = 2 * index + 2;
  if (tree[index] != INT_MAX) {
    if (tree[index] > temp)
      insert(tree, temp, left);
    else if (tree[index] < temp)
      insert(tree, temp, right);
    else
      return;
  } else {
    tree[index] = temp;
  }
}

int main() {
  int n = 0;
  int tree[MAX_SIZE + 10];

  while (scanf("%d", &n) != EOF && n) {
    for (int i = 0; i < MAX_SIZE; i++) tree[i] = INT_MAX;

    for (int i = 0, temp = 0; i < n; i++) {
      scanf("%d", &temp);
      insert(tree, temp);
    }

    mid_order(tree);
    printf("\n");
    pre_order(tree);
    printf("\n");
  }

  return 0;
}
