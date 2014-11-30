// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week9/1001_encoding_and_transport.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1001&cid=1602
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

#define MAX_SIZE 255

int main() {
  int n = 0, nums[MAX_SIZE + 5] = { 0 };
  char dict[MAX_SIZE + 5][MAX_SIZE+5] = { 0 };
  char s[MAX_SIZE + 5] = { 0 };

  // input
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    // here we scan a char, thus the '\n' left in the buffer will be scaned
    // too. But it doesn't matter
    scanf("%c", dict[i]);
  }
  scanf("%s", s);

  // process the |s| string to numbers
  int j = 0;
  for (char* temp = strtok(s, "-");
       temp != NULL;
       temp = strtok(NULL, "-"), j++) {
    nums[j] = atoi(temp);
  }

  // output the encoded string
  int count = n + 1;
  for (int i = 0; i < j; i++) {
    if (nums[i]) {
      strcat(dict[count], dict[nums[i]]);
    }
    if (!nums[i] || i == j-1) {
      if (count > n + 1) printf(" ");
      printf("%s", dict[count]);
      count++;
    }
  }

  return 0;
}
