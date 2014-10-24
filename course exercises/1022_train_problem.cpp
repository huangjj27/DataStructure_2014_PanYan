// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1022_train_problem.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1022&cid=1405
#include <iostream>
#include <string>
#include <stack>

#define MAX_SIZE 9
using std::cin;
using std::cout;
using std::endl;
using std::string;

int IsStack(int *in_order, int *data, int n) {
  std::stack<int> order;

  // for each case, if the data match the top then we pop from the stack,
  // and goto the next data, otherwise we push the bullet into the stack.
  // if the stack is empty and we haven't search all 10 datas, we need to
  // push a new number into the stack.
  for (int i = 0, j = 0; i < n; i++) {
    while (order.empty() || (data[i] != order.top() && j < n))
      order.push(in_order[j++]);
    if (data[i] == order.top()) order.pop();
  }

  // if the stack is not empty, that means the datas' order doesn't
  // match the chareteristic of stack.
  return order.empty();
}

void Output(int *in_order, int *data, int n) {
  std::stack<int> order;

  for (int i = 0, j = 0; i < n; i++) {
    while (order.empty() || (data[i] != order.top() && j < n)) {
      order.push(in_order[j++]);
      cout << "in" << endl;
    }
    if (data[i] == order.top()) {
      order.pop();
      cout << "out" << endl;
    }
  }
}

int main() {
  int trains_num = 0;

  while (cin >> trains_num) {
    string in_order_str, out_order_str;
    cin >> in_order_str >> out_order_str;
    int in_order[MAX_SIZE + 1], out_order[MAX_SIZE + 1];

    // conver the in order and the out order to digits so we can be  more
    // easier to use them
    for (int i = 0; i < trains_num; i++) {
      in_order[i] = in_order_str[i] - '0';
      out_order[i] = out_order_str[i] - '0';
    }

    if (IsStack(in_order, out_order, trains_num)) {
      cout << "Yes." << endl;
      Output(in_order, out_order, trains_num);
    } else {
      cout << "No." << endl;
    }
    cout << "FINISH" << endl;
  }

  return 0;
}
