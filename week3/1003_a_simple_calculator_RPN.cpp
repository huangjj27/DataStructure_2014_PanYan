// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week3/1003_a_simple_calculator_RPN.cpp:
// A Simple Calculator@Data Structure course 2014 by Pan Yan
// http://soj.me/show_problem.php?pid=1003&cid=1481
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

using std::fixed;
using std::setprecision;
using std::string;
using std::stringstream;
using std::stack;
using std::queue;
using std::pair;

string to_string(const double num) {
  stringstream ss;
  string str;
  ss << num;
  ss >> str;
  return str;
}

double to_double(const string str) {
  stringstream ss;
  double num;
  ss << str;
  ss >> num;
  return num;
}

string Prepocess(const string &str) {
  string str_temp;
  for (int i = 0; str[i]; i++) {
    if (i == 0 || 
        ((str[i] == '-'  || str[i] == '+') && !isdigit(str[i-1])))
      str_temp += '%';
    str_temp += str[i];
  }
  return str_temp;
}

queue<string> getRPN(const string& str) {
  queue<string> RPN;
  stack< pair<char, int> > operators;
  string str_temp = Prepocess(str);
  double number;
  char op;
  bool is_sign = false;
  for (str_temp += "#"; str_temp[0] != '#';) {
    if (str_temp[0] == '%' || isdigit(str_temp[0])) {
      stringstream ss;
      ss << str_temp;
      if (str_temp[0] == '%') {
        char ch;
        ss >> ch;
      }
      ss >> number;
      ss >> str_temp;
      RPN.push(to_string(number));
    } else {
      stringstream ss;
      ss << str_temp;
      ss >> op;
      ss >> str_temp;

      pair<char, int> new_op(op, 0);
      if (op == '*' || op == '/')
        new_op.second = 2;
      else if (op == '+' || op == '-')
        new_op.second = 1;

      while (!operators.empty() && operators.top().second >= new_op.second) {
        char temp_ch = operators.top().first;
        RPN.push(string(1, temp_ch));
        operators.pop();
      }
      operators.push(new_op);
    }
  }
  while (!operators.empty()) {
    char temp_ch = operators.top().first;
    RPN.push(string(1, temp_ch));
    operators.pop();
  }

  return RPN;
}

double Calculate(queue<string> RPN) {
  stack<double> numbers;
  for (; !RPN.empty(); RPN.pop()) {
    string temp(RPN.front());
    if (temp == "*" || temp == "/" || temp == "+" || temp == "-") {
      double right = numbers.top();
      numbers.pop();
      double left = numbers.top();
      numbers.pop();
      if (temp == "*")
        numbers.push(left * right);
      if (temp == "/")
        numbers.push(left / right);
      if (temp == "+")
        numbers.push(left + right);
      if (temp == "-")
        numbers.push(left - right);
    } else {
      numbers.push(to_double(temp));
    }
  }
  return numbers.top();
}

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
  int test_cases;
  for (cin >> test_cases, getchar(); test_cases; test_cases--) {
    string str0, str;
    std::getline(cin, str0);
    // abandon all whitespaces.
    for (int i = 0; str0[i]; i++) {
      if (str0[i] != ' ')
        str += str0[i];
    }

    queue<string> RPN = getRPN(str);
    double result = Calculate(RPN);
    cout << fixed << setprecision(3) << result << endl;
  }
  return 0;
}
