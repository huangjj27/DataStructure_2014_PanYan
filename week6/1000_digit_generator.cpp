// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week6/1000_digit_generator.cpp: DataStucture2014@PanYan
// http://soj.me/show_problem.php?pid=1000&cid=1550
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void subStringsSort(int N, string sub[8]) {
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (sub[i] + sub[j] > sub[j] + sub[i]) {
        string temp = sub[i];
        sub[i] = sub[j];
        sub[j] = temp;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    string sub[8];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> sub[i];
    subStringsSort(N, sub);
    for (int i = 0; i < N; i++) cout << sub[i];
    cout << endl;
  }
  return 0;
}
