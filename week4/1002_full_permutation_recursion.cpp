// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week4/1002_full_permutation.cpp:@Data Structure course 2014 by Pan Yan
// http://soj.me/show_problem.php?pid=1002&cid=1502
// solve the problem with a recursion algorithm
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 10

using std::cin;
using std::cout;
using std::endl;

using std::vector;

using std::sort;

void Permutation(vector<int>& numbers, int start, int end,
                 vector< vector<int> >& list) {
  if (start > end) {
    vector<int> sequence(numbers);
    list.push_back(sequence);
  } else {
    for (int i = start; i <= end; i++) {
      std::swap(numbers[start], numbers[i]);
      Permutation(numbers, start + 1, end, list);
      std::swap(numbers[start], numbers[i]);
    }
  }
}

int main() {
  int test_cases, number;
  for (cin >> test_cases;
       test_cases && cin >> number && (0 < number && number < 10);
       test_cases--) {
    vector< vector<int> > list;
    vector<int> numbers;
    for (int i = 0; i < number; i++) numbers.push_back(i + 1);
    Permutation(numbers, 0, number - 1, list);

    sort(list.begin(), list.end());
    for (vector< vector<int> >::iterator it = list.begin();
         it != list.end();
         it++) {
      for (int i = 0; i < number; i++) cout << (*it)[i];
      cout << endl;
    }
  }

  return 0;
}
