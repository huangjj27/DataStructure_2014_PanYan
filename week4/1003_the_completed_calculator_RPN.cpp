// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week4/1003_the_completed_calculator_RPN.cpp:
// @Data Structure course 2014 by Pan Yan
// http://soj.me/show_problem.php?pid=1003&cid=1502
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

// two string convertion functions
// we define these funitons here just because sicily doesn't allow us to
// use functiong std::to_string() & std::stod()
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

// function Prepocess:
// determines whether a char '-'or '+', is an operator or a sign of a number.
// for the later, we add a '%' before the char to show that it's a sign
// and can be scanf with the digits following as a double number.
string Prepocess(const string &str) {
  string str_temp;
  for (int i = 0; str[i]; i++) {
    if ( (i == 0 && !isdigit(str[i]) && str[i] != '(')
       || (i && (str[i] == '-' || str[i] == '+') && str[i-1] == '(') )
        str_temp += '%';
    str_temp += str[i];
  }
  return str_temp;
}

// function getRPN:
// changes an infix notation(str) to its postfix notation.
queue<string> getRPN(const string& str) {
  queue<string> RPN;
  stack< pair<char, int> > operators;
  string str_temp = Prepocess(str);  // adds sign mark before negative numbers
  double number;
  char op;

  // add an end mark before dealing with the string.
  // otherwise we will get into an infinite loop.
  for (str_temp += "#"; str_temp[0] != '#';) {
    // if a number is non-negative, we can scan its first digit
    // otherwise we scan the number's sign mark
    if (str_temp[0] == '%' || isdigit(str_temp[0])) {
      stringstream ss;
      ss << str_temp;
      if (str_temp[0] == '%') {  // we don't want to have a '%'
        char ch;                 //  in our RPN stack.Throws it away~
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

      // gives priority for each operator
      pair<char, int> new_op(op, 0);
      if (op == '*' || op == '/')
        new_op.second = 2;
      else if (op == '+' || op == '-')
        new_op.second = 1;
      else if (op == '(' || op == ')')
        new_op.second = 3;

      // if the operator is a right bracket,
      // DON'T PUT IT INTO THE STACK!
      // puts the operators to the RPN stack until meets a left bracket.
      // and the first-meet left bracket matches the current right bracket.
      if (new_op.first == ')') {
        while (operators.top().first != '(') {
          char temp_ch = operators.top().first;
          RPN.push(string(1, temp_ch));
          operators.pop();
        }
        operators.pop();  // don't forget to pop out the left bracket matched.
        continue;         // the work of dealing a right bracket is done.
      }

      // while the current operator's priority is no bigger than the top of
      // operators stack, puts the operators from the operators stack to
      // RPN stack so that we comfirm the calculate-order is right.
      while (!operators.empty() && operators.top().second >= new_op.second
             && (operators.top().first != '('
                && operators.top().first != ')')) {
        char temp_ch = operators.top().first;
        RPN.push(string(1, temp_ch));
        operators.pop();
      }
      operators.push(new_op);
    }
  }

  // don't forget that there may be some operator remains
  // in the operators stack
  while (!operators.empty()) {
    char temp_ch = operators.top().first;
    RPN.push(string(1, temp_ch));
    operators.pop();
  }

  return RPN;
}

// funtion Calculate:
// supposes that we now get a correct postfix notation of the expression
// we want to calculate, then we can esaily get result through this function!
double Calculate(queue<string> RPN) {
  stack<double> numbers;
  for (; !RPN.empty(); RPN.pop()) {
    string temp(RPN.front());

    // in the RPN stack, we have dealt all brackets
    // and only these 4 operations remains
    // and each element of the queue is either a number or a operator

    // if we get a operator, pop the top-2 numbers from the numbers stack,
    // do the corresponding operation, and push the result back
    // to the numbers stack
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

  // when we do all operations,
  // there will only the result in the numbers stack.
  return numbers.top();
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
