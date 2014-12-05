// Copyright (c) Junjie_Huang@SYSU(SNO:13331087). All Rgights Reserved.
// week10/1002_groups.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1002&cid=1618
#include <iostream>
#include <vector>
#include <cstdio>

#define MAX_SIZE 1000

using std::vector;

int getSum(vector<int>* hash, int T) {
  int sum = 0;
  for (int i = 0; i < T; i++) {
    int n = hash[i].size();
    sum += (1+n)*n/2;
  }
  return sum;
}

int main() {
  int N = 0, T = 0;
  while (scanf("%d %d", &N, &T) != EOF) {
    vector<int> hash[12];
    int num = 0, sum = 0;
    for (int i = 0; i < N; i++) {
      scanf("%d", &num);
      hash[num%T].push_back(num);
    }

    sum = getSum(hash, T);

    for (int i = 0; i < T; i++) {
      for (int j = hash[i].size() - 1; j >= 0; j--) {
        printf("%d ", hash[i][j]);
      }
      printf("\n");
    }
    printf("%.3f\n", (sum + 0.0) / N);
  }

  return 0;
}
