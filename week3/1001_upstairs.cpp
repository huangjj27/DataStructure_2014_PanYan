// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1001_upstairs.cpp: DataStructure2014@PanYan
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int ways(int single_steps, int double_steps) {
  int total_steps = single_steps + double_steps;
  if (single_steps > 0 && double_steps == 0) return 1;  // special case

  // divides total steps into each concrete sistuation
  // for example, when we need to climb 12 stairs, first we consider the
  // sistuation that all the 12 steps are single, then converst one double step
  // to 2 single steps and considers the situation.
  // all sistuaionts are considered when there is none double steps.
  int up = 1, down = 1;
  for (int i = 0; i < double_steps; i++) {
    up *= (total_steps - i);
    down *= (i + 1);
  }
  return up / down;
}

int main() {
  // input the test cases
  int T;
  cin >> T;
  while (T--) {
    int steps = 0, single_steps = 0, double_steps = 0;
    cin >> steps;

    int sum = 0;
    for (single_steps = steps;
         single_steps >= 0 && double_steps >= 0;
         single_steps -= 2, double_steps += 1) {
      sum += ways(single_steps, double_steps);
    }

    cout << sum << endl;
  }
  return 0;
}
