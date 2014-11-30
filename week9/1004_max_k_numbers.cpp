// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week9/1003_sets.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1003&cid=1602
#include <cstdio>

#define MAX_SIZE 1000000

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
  // each time we search the larger child for the next step
  // loop until we have moved all larger child nodes to the upper node
  for (int root = start;
       2 * root + 1 < end;
       root = larger_child) {
    larger_child = 2 * root + 1;  // first dim larger_child as the left_child
    if (larger_child < end - 1 && nums[larger_child + 1] > nums[larger_child])
      larger_child++;

    if (nums[root] < nums[larger_child])
      swap(nums[root], nums[larger_child]);
    else
      break;
  }
}

inline void print(int nums[], int start, int end) {
  // outputs the data.
  for (int k = end - 1; k >= start; k--) {
    if (k != end - 1) printf(" ");
    printf("%d", nums[k]);
  }
  printf("\n");
}

inline void heap_sort(int nums[], int start, int end) {
  // sort with a maxinum heap.
  // @Param |nums|: the data array regarded as a heap
  // @|start|: the beginning index of |nums|
  // @|end|: the non-include end index of |nums|

  // build up a maxinum heap for the first time
  for (int i = end / 2; i >= start; i--) sort_branch(nums, i, end);

  // Now, the max number of |nums| between |start| and |end|-1 is |nums[start]|
  // for we have built up a maxinum heap. Then swap it with the last number
  // so the last number will be the largest.
  // Then sort the branch from the root to find the next maxinum number and
  // do the same again. Loop until there is only an element left, which means
  // we have sorted all elements
  for (int j = end - 1; j > start; j--) {
    swap(nums[0], nums[j]);
    sort_branch(nums, start, j);

  }
}

int main() {
  int N, K, data[MAX_SIZE + 10];

  // whether a testcase is scaned
  while (scanf("%d %d", &N, &K) != EOF) {

    for (int i = 0; i < N; i++) scanf("%d", &data[i]);
    heap_sort(data, 0, N);

    print(data, N - K, N);
  }

  return 0;  // end main
}
