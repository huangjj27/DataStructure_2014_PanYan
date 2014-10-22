// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 13331087_03.cpp: A Simple Calculator@Data Structure course 2014 by Pan Yan
// http://soj.me/show_problem.php?pid=1003&cid=1481
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

using std::fixed;
using std::setprecision;
using std::string;
using std::stack;

double getNumber(string str, int& i) {
  double number = 0;
  bool is_nagetive = false;
  if (str[i] == '-') {
    is_nagetive = true;
    i++;
  }
  for (; isdigit(str[i]); i++) number = number * 10 + (str[i] - '0');
  if (is_nagetive) number = 0 - number;

  return number;
}

int main() {
  // input the test cases
  int T;
  cin >> T;
  getchar();
  while (T--) {
    string str0, str1;
    stack<double> numbers;

    std::getline(cin, str0);

    // abandent all whitespaces.
    for (int i = 0; str0[i]; i++) {
      if (str0[i] != ' ')
        str1 += str0[i];
    }

    int i = 0;
    numbers.push(getNumber(str1, i));
    while (str1[i]) {
      if (str1[i] == '*') {
        double temp = getNumber(str1, ++i);
        temp *= numbers.top();
        numbers.pop();
        numbers.push(temp);
        continue;
      }
      if (str1[i] == '/') {
        double temp = getNumber(str1, ++i);
        temp = numbers.top() / temp;
        numbers.pop();
        numbers.push(temp);
        continue;
      }
      if (str1[i] == '+') {
        numbers.push(getNumber(str1, ++i));
        continue;
      }
      if (str1[i] == '-') {
        double sum = 0;
        for (; !numbers.empty(); numbers.pop()) sum += numbers.top();

        double temp = getNumber(str1, ++i);
        numbers.push(sum - temp);
        continue;
      }
    }

    double sum = 0;
    for (; !numbers.empty(); numbers.pop()) sum += numbers.top();
    cout << fixed << setprecision(3) << sum << endl;
  }
  return 0;
}
