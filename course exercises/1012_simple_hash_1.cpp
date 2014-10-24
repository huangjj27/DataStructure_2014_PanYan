// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1012_simple_hash_1.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1012&cid=1405
#include <iostream>

#define MAX_SIZE 10000
using std::cin;
using std::cout;
using std::endl;

int main() {
  int n = 0, m = 0;
  int hash_map[MAX_SIZE + 1] = { 0 };
  cin >> n >> m;

  int number = 0;
  for (int i = 0; i < n; i++) {
    cin >> number;
    int key = number%m;
    while (hash_map[key]) key++;
    key %= m;
    hash_map[key] = number;
  }

  for (int i = 0; i < m; i++) {
    cout << i << "#";
    if (hash_map[i])
      cout << hash_map[i];
    else
      cout << "NULL";
    cout << endl;  
  }
  return 0;
}
