// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// myqueue.h: using 2 STL stacks as a queue
#include <stack>

using std::cin;
using std::cout;
using std::endl;

using std::stack;

enum ERROR_CODE {overflow, underflow};

class Queue {
 public:
  // default constructor & destructor
  // shows the constructing or destructing message on console
  Queue() { cout << "Queue constructing." << endl; }
  ~Queue() {
     if (!IsEmpty())
       cout << "Elements remain. Now will destroy all elements" << endl;
     cout << "Queue destructing." << endl;
  }

  // determine if there is any elements left in either of the two stacks.
  bool IsEmpty() const {
    return first_stack_.empty() && second_stack_.empty();
  }

  // get the address of the first element
  // if no element is in the queue, we can't get the address and
  // we need to throw an error code.
  int &front() {
    if (!IsEmpty()) {
      SecondToFirst();
      return first_stack_.top();
    } else {
      throw underflow;  // if there is no element in the queue, throw an error.
    }
  }

  // add a new element to the trail of the queue
  // @Param a: the new element we want to push to the queue.
  void push(const int a) {
    second_stack_.push(a);
  }

  // delete the front element of the queue and
  // make the element after the previous front be the new front element
  void pop() {
    SecondToFirst();
    if (!first_stack_.empty())
      first_stack_.pop();
    else
      throw underflow;
  }

 private:
  stack<int> first_stack_;   // the head of the queue
  stack<int> second_stack_;  // the end of the queue

  // if there is no data in the first_stack_ but some in the second_stack_
  // move them to the first_stack_
  void SecondToFirst() {
    if (first_stack_.empty() && !second_stack_.empty()) {
      while (!second_stack_.empty()) {
        int temp_top = second_stack_.top();
        second_stack_.pop();
        first_stack_.push(temp_top);
      }
    }
  }
};
