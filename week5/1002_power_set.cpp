// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week5/1002_power_set.cpp: DataStructure2014@PanYan
// http://soj.me/contest_detail.php?cid=1523
#include <iostream>

#define MAX_SIZE 15
using std::cin;
using std::cout;
using std::endl;

// Recursion to slove the problem
// making the rule of that one set A is smaller than another only if
// the first number diferent in A is smaller than the other
void getPowerSet(int position, int n, int* set) {
  if (position == n) {
    cout << "{";
    for (int i = 0, count = 0; i < n; i++) {
      if (i && count && set[i]) cout << ",";
      if (set[i]) {
        cout << set[i];
        count++;
      }
    }
    cout << "}" << endl;
  } else {
    set[position] = 0;
    getPowerSet(position + 1, n, set);

    set[position] = n - position;
    getPowerSet(position + 1, n, set);
  }
}

int main() {
  int test_cases;
  for (cin >> test_cases; test_cases; test_cases--) {
    int n, set[MAX_SIZE + 1] = { 0 };
    cin >> n;
    // reversed sort
    for (int i = n; i; i--) {
      set[n - i] = i;
    }

    getPowerSet(0, n, set);
  }

  return 0;
}
