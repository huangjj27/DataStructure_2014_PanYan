// Copyright (c) Junjie_Huang@SYSU(SNO:1331087). All Rights Reserved.
// week4/1000_hanoi.cpp: DataStructure2014@PanYan
// using recuration to solve the problem
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void Hanoi(int disc_num, int start, int end, int temp) {
  if (disc_num <= 0) {
    return;
  } else {
    Hanoi(disc_num - 1, start, temp, end);
    cout << "move disk " << disc_num << " from peg " << start
      << " to peg " << end << endl;
    Hanoi(disc_num - 1, temp, end, start);
  }
}

int main() {
  int test_cases;
  for (cin >> test_cases; test_cases; test_cases--) {
    int disc_num;
    cin >> disc_num;
    Hanoi(disc_num, 1, 3, 2);
  }

  return 0;
}
