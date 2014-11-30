// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week9/1002_heap_sort.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1002&cid=1602
// in the file, we define many inline functions and pass params as reference to
// reduce the runtime.
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

  // from node(|root|)
  // each time we search the  lager child for the next step
  // loop until we have moved all larger child nodes to the upper node
  for (int root = start, temp = nums[root];
       2*root+1 < end;
       root = lager_child) {
    lager_child = 2 * root + 1;  // first dim lager_child as the left child
    if (lager_child < end - 1 && nums[lager_child + 1] > nums[lager_child])
      lager_child++;

    if (temp < nums[lager_child])
      swap(nums[root], nums[lager_child]);
    else
      break;
  }
}

inline void print(int nums[], int start, int end) {
  // outputs the data.
  for (int k = start; k < end; k++) {
    if (k) printf(" ");
    printf("%d", nums[k]);
  }
  printf("\n");
}

inline void heap_sort(int nums[], int start, int end) {
  for (int i = end / 2 ; i >= start; i--) sort_branch(nums, i, end);
  print(nums, start, end);

  for (int j = end - 1; j > start; j--) {
    swap(nums[0], nums[j]);
    sort_branch(nums, start, j);  // build a maxinum_heap between 0 and j-1;

    // outputs data eachtime we build a maxinum heap
    print(nums, start, end);
  }
}

int main() {
  int n = 0, nums[MAX_SIZE + 10];  // initializes the data

  // inputs data
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    heap_sort(nums, 0, n);
  }

  return 0;  // end main
}
