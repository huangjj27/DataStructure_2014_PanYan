// Copyright (c) Junjie_Huang@SYSU(SNO:13331087). All Rgights Reserved.
// week11/1000_sicily_1156.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1000&cid=1642
#include <cstdio>
#include <cstring>

#define MAX_SIZE 1000

struct Node {
  char data;
  int left;
  int right;
};


void pre_order(Node node[],int index) {
  if (node[index].data) {
    printf("%c", node[index].data);
    pre_order(node, node[index].left);
    pre_order(node, node[index].right);
  }
}

int main() {
  int n = 0;
  Node tree[MAX_SIZE + 10];

  while (scanf("%d", &n) != EOF) {
    memset(tree, 0, sizeof(tree));

    int root = 0, index = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d ", &index);
      scanf("%c %d %d",
            &tree[index].data, &tree[index].left, &tree[index].right);

      // finds the root node
      // because the root only appears once while the rest node will appear
      // twice and by the EOR operation, the number left finally must the root.
      root = root ^ index ^ tree[index].left ^ tree[index].right;

    }

    pre_order(tree, root);
    printf("\n");
  }

  return 0;
}
