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

// Pre:
// @|tree[]|: the array needs to traverse
// @|pre|: the string printed by traversing a tree in pre-order
// @|mid|: the string printed by traversing a tree in mid-order
// @|index|: the index of parent node in the |tree[]|.
// Post: None
// Usage: finds the root node of a tree and sperates the |mid| with root so we
// can point out the left sub-tree and the right one. Recurses the function
// until all the elements are insert to the |tree|
void rebuild(char tree[], string pre, string mid, int index = 0) {
  // records the left child |left| and the right child |right|
  // of the parent node
  int left = 2 * index + 1, right = 2 * index + 2;
  if (pre.length()) {  // Recursions end when all the elements are inserted.
    tree[index] = pre[0];  // insert the data of the parent node

    // finds the position of root node from |mid|
    int temp = mid.find(pre[0]);

    // Recursions. Seperates the tree to its left sub-tree and the right one.
    // and the |left| and |right| will be the new parent nodes.
    rebuild(tree, pre.substr(1, temp), mid.substr(0, temp), left);
    rebuild(tree, pre.substr(temp + 1), mid.substr(temp + 1), right);
  }
}

// Pre:
// @|tree[]|: the binary tree we want to traverse with BFS. Here because
// we use an array to store the data, so we just need to traverse the array
// by the index.
// Post: Node
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
