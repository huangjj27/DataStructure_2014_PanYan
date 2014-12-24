// Copyright (c) Junjie_Huang@SYSU(SNO:13331087). All Rgights Reserved.
// week12/1002_huffman_coding.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1002&cid=1654
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_SIZE 1000
#define MAX_INT 65535

typedef struct {
  char ch;
  int w;
  int left_index;
  int right_index;
  bool is_visited;
  int depth;
} Node;

bool cmp(Node a, Node b) {
  return a.w < b.w;
}

bool is_built(Node data[], int length) {
  for (int i = 0; i < length; i++) {
    if (!data[i].is_visited) return false;
  }
  return true;
}

int find_min(Node data[], int length) {
  int min_index = 0;
  int min_w = MAX_INT;
  for (int i = 0; i < length; i++) {
    if (!data[i].is_visited && data[i].w < min_w) {
      min_index = i;
      min_w = data[i].w;
    }
  }
  data[min_index].is_visited = true;

  return min_index;
}

void get_depth(Node data[], int root) {
  int left = data[root].left_index;
  int right = data[root].right_index;
  if (left != -1) {
    data[left].depth++;
    get_depth(data, left);
  }
  if (right != -1) {
    data[right].depth++;
    get_depth(data, right);
  }
}

int main() {
  int N;
  Node data[MAX_SIZE + 5];
  scanf("%d\n", &N);
  for (int i = 0; i < N; i++) {
    scanf("%c %d\n", &data[i].ch, &data[i].w);
    data[i].left_index = data[i].right_index = -1;
    data[i].is_visited = false;
    data[i].depth = 0;
  }

  for (int i = N; !is_built(data, i-1); i++) {
    int left = data[i].left_index = find_min(data, i);
    int right = data[i].right_index = find_min(data, i);
    data[i].w = data[left].w + data[right].w;
    data[i].is_visited = false;
    data[i].depth = 0;
    get_depth(data, i);
  }

  int sum = 0;
  for (int i = 0; i < N; i++) sum += data[i].depth*data[i].w;
  printf("%d\n", sum);

  return 0;
}
