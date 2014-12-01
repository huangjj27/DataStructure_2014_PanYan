// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week9/1004_max_k_numbers_mininum_heap.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1004&cid=1602
#include <cstdio>
#include <cstring>

#define MAX_SIZE 10000

inline void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

inline void sort_branch(int nums[], int start, int end) {
  // sorts a branch making the mininum in the brach to the leaf
  // @Param |nums|: the data array regarded as a heap
  // @|start|: the beginning index of |nums|
  // @|end|: the non-include end index of |nums|

  int larger_child;  // find the larger child and record the node

  // from node(|root|)
  // each time we search the lager child for the next step
  // loop until we have moved all larger child nodes to the upper node
  for (int root = start, temp = nums[root];
       2 * root + 1 < end;
       root = larger_child) {
    larger_child = 2 * root + 1;  // first dim larger_child as the left_child
    if (larger_child < end - 1 && nums[larger_child + 1] < nums[larger_child])
      larger_child++;

    if (temp > nums[larger_child])
      swap(nums[root], nums[larger_child]);
    else
      break;
  }
}

inline void print(int nums[], int start, int end) {
  // outputs the data.
  for (int k = start; k < end; k++) {
    if (k > start) printf(" ");
    printf("%d", nums[k]);
  }
  printf("\n");
}

int main() {
  int N, K, data[MAX_SIZE + 10];

  // whether a testcase is scaned
  while (scanf("%d %d", &N, &K) != EOF) {
    memset(data, 0, K*sizeof(*data));

    for (int i = 0, temp = 0; i < N; i++) {
      scanf("%d", &temp);
      if (temp > data[0]) data[0] = temp;
      sort_branch(data, 0, K);
    }

    for (int j = K - 1; j > 0; j--) {
      swap(data[0], data[j]);
      sort_branch(data, 0, j);
    }
    print(data, 0, K);
  }

  return 0;  // end main
}
