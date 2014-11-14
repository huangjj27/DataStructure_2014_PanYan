// Copyright (c) 2014 by Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1001_inserting_sort.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1001&cid=1567
#include <iostream>
#include <queue>

#define max_size 105

using std::cin;
using std::cout;
using std::endl;

bool isSorted(int data[], int size) {
  for (int i = 0; i < size - 1; i++) {
    if (data[i] > data[i + 1]) return false;
  }
  return true;
}

void printData(int data[], int N) {
  for (int k = 0; k < N; k++) cout << data[k] << " ";
  cout << endl;
}

int main() {
  int data[max_size] = { 0 };
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> data[i];

  printData(data, N);
  for (int i = 1; i < N; i++) {
    int temp = data[i];
    int j = i - 1;
    while (j >= 0 && data[j] > temp) {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = temp;
    if (j == i - 1) continue;
    printData(data, N);
  }
  return 0;
}
