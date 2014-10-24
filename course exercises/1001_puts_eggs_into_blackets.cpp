// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1001_puts_eggs_into_blackets.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1001&cid=1405
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// recuration algorithm.
// all the eggs or blackets are the same.
int findNumOFWays(int eggs_num, int blacket_num) {
  // when there is only a blacket or an egg,
  // there will be only one way to put egg(s).
  if (eggs_num == 1 || blacket_num == 1) return 1;

  // if blackets are no more than eggs, then almost blackets of eggs' number
  // are used. In this case only one way can used.
  // then we can put the eggs with at least one blacket empty, which we use
  // recuration algorithm to solve.
  if (eggs_num <= blacket_num)
    return 1 + findNumOFWays(eggs_num, eggs_num - 1);
  // if blackets are less than eggs, we can put eggs with all the blackets,
  // or at least one blackets empty.
  else
     return findNumOFWays(eggs_num - blacket_num, blacket_num) +
    findNumOFWays(eggs_num, blacket_num - 1);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int eggs_num, blackets_num;
    cin >> eggs_num >> blackets_num;
    cout << findNumOFWays(eggs_num, blackets_num) << endl;
  }
}
