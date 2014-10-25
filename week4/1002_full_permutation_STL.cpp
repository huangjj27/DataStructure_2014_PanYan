// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week4/1002_full_permutation.cpp:@Data Structure course 2014 by Pan Yan
// http://soj.me/show_problem.php?pid=1002&cid=1502
// using STL to solve the problem
#include <iostream>
#include <algorithm>

#define MAX_SIZE 10

using std::cin;
using std::cout;
using std::endl;

using std::next_permutation;

int main() {
  int test_cases, number;
  for (cin >> test_cases;
       test_cases && cin >> number && (0 < number && number < 10);
       test_cases--) {
    int numbers[MAX_SIZE + 1];
    for (int i = 0; i < number; i++) numbers[i] = i + 1;
    do {
      for (int i = 0; i < number; i++) cout << numbers[i];
      cout << endl;
    } while (next_permutation(numbers, numbers + number));
  }

  return 0;
}
