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

void sort_branch(int nums[], int start, int end) {
  // sort a branch into a reverse order
  // |nums|: the data array
  // |start|: the beginning index of |nums|
  // |end|: the non-include end index of |nums|

  int lager_child;  // find the larger child and record the node
  int root, temp;

  // from node(|root|)
  // each time we search the  lager child for the next step
  // loop until we have moved all larger child nodes to the upper node
  for (root = start, temp = nums[root];
       2 * root + 1 < end;
       root = lager_child) {
    lager_child = 2 * root + 1;  // first dim lager_child as the left child
    if (lager_child < end - 1 && nums[lager_child + 1] > nums[lager_child])
      lager_child++;

    if (temp < nums[lager_child])
      nums[root] = nums[lager_child];
    else
      break;
  }
  nums[root] = temp;
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
  for (int i = end / 2; i >= start; i--) sort_branch(nums, i, end);

  for (int j = end - 1; j > start; j--) {
    swap(nums[0], nums[j]);
    sort_branch(nums, start, j);  // build a maxinum_heap between 0 and j-1;
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
