// Copyright (c) Junjie_Huang@SYSU(SNO:13331087). All Rgights Reserved.
// week10/1000_where_is_farther.cpp: DataStructure2014@PanYan
// http://soj.sysu.edu.cn/show_problem.php?pid=1000&cid=1618
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cctype>

#define MAX_SIZE 10000

using std::cin;
using std::cout;
using std::endl;

using std::string;

int getNameNum(string name, int m) {
  int sum = 0;
  for (int i = 0; name[i]; i++) {
    sum += (tolower(name[i]) - 'a') + 1;
  }
  return sum%m;
}

int insertHash(string* hash, string& name, int m) {
  int num = getNameNum(name, m);
  int find = 1;
  while (num < m) {
    if (hash[num] == "") {
      hash[num] = name;
      break;
    } else {
      if (num == m - 1)
        num = 0;
      else
        num++;
      find++;
    }
  }
  return find;
}

int main() {
  int n = 0, m = 0;
  while (scanf("%d %d", &n, &m) != EOF) {
    string hash[MAX_SIZE + 10];
    string name;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> name;
      sum += insertHash(hash, name, m);
    }

    for (int i = 0; i < m; i++) {
      cout << i << ":";
      if (hash[i] != "")
        cout << hash[i];
      else
        cout << "NULL";
      cout << endl;
    }
    cout << std::fixed << std::setprecision(3) << (sum + 0.0) / n << endl;
  }

  return 0;
}
