// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1002_shooting_game.cpp: DataStructure2014@PanYan
// determines whether an order given is suit to the characteristic of stacks
// http://soj.me/show_problem.php?pid=1002&cid=1481
#include <iostream>
#include <stack>

#define max_size 10

using std::cin;
using std::cout;
using std::endl;

int main() {
  // input test cases
  int T;
  cin >> T;
  while (T--) {
    std::stack<int> order;
    int data[max_size] = { 0 };
    for (int i = 0; i < max_size; i++) cin >> data[i];  // get the datas


    // for each case, if the data match the top then we pop from the stack,
    // and goto the next data, otherwise we push the bullet into the stack.
    // if the stack is empty and we haven't search all 10 datas, we need to
    // push a new number into the stack.
    for (int i = 0, j = 1; i < 10; i++) {
      while (order.empty() || (data[i] != order.top() && j <= 10))
        order.push(j++);
      if (data[i] == order.top()) order.pop();
    }

    // if the stack is not empty, that means the datas' order doesn't
    // match the chareteristic of stack.
    if (order.empty())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
