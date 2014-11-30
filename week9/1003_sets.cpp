// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week9/1003_sets.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1003&cid=1602
#include <cstdio>
#include <cstring>

#define MAX_SIZE 200

// name of the sets
enum { A, B, AandB, AorB, AnotB };

bool find(int arr[], int size, int num) {
  // find if |num| in the array |arr| in the range of |size|
  for (int i = 0; i < size; i++) {
    if (arr[i] == num) return true;
  }
  return false;
}

void print(int arr[], int size) {
  // outputs a array in the range of |size|
  for (int i = 0; i < size; i++) printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int M, N, data[5][MAX_SIZE + 10];

  // whether a testcase is scaned
  while (scanf("%d %d", &M, &N) != EOF) {
    // initialization of the data
    int size_A = M, size_B = N, size_AandB = 0, size_AorB = 0, size_AnotB = 0;
    for (int i = 0; i < 5; i++)
      memset(data, 0, sizeof(data));

    // input the testcase's data
    for (int i = 0; i < size_A; i++) {
      scanf("%d", &data[A][i]);
      data[AorB][size_AorB++] = data[A][i];  // the data in set A must be in set AorB
    }
    for (int i = 0; i < size_B; i++) scanf("%d", &data[B][i]);

    for (int i = 0; i < size_A; i++) {
      if (find(data[B], size_B, data[A][i]))
        data[AandB][size_AandB++] = data[A][i];
      else
        data[AnotB][size_AnotB++] = data[A][i];
    }

    for (int i = 0; i < size_B; i++) {
      if (!find(data[A], size_A, data[B][i]))
        data[AorB][size_AorB++] = data[B][i];
    }

    // output
    print(data[AandB], size_AandB);
    print(data[AorB], size_AorB);
    print(data[AnotB], size_AnotB);
  }

  return 0;  // end main
}
