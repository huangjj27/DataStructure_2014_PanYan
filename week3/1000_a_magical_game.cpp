// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1000_a_magical_game.cpp: Data_Structure2014@PanYan
// using STL containers, queue and stack, to reverse the operation and get the
// correct order.
// http://soj.me/show_problem.php?pid=1000&cid=1481
#include <iostream>
#include <queue>
#include <stack>

using std::cin;
using std::cout;
using std::endl;

using std::queue;
using std::stack;

int main() {
  // input the test cases
  int T;
  cin >> T;
  while (T--) {
    int cards_num;
    cin >> cards_num;

    // now we push the cards into the queue with a reversed operation
    queue<int> que;
    for (int i = cards_num; i; i--) {
      que.push(i);
      for (int j = 1; j < i; j++) {
        int temp = que.front();
        que.pop();
        que.push(temp);
      }
    }

    // now we get the reversed order of the cards.
    // and we use a stack to get the original order.
    stack<int> order;
    for (; !que.empty(); que.pop()) order.push(que.front());

    for (; !order.empty(); order.pop()) cout << order.top() << " ";
    cout << endl;
  }

  return 0;
}
