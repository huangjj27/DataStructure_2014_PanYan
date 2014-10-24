// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1029_string_reversion.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1029&cid=1405
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  int test_cases = 0;
  cin >> test_cases;
  while (test_cases--) {
    string str, output;
    size_t begin_pos = 0, end_pos = 0;

    cin >> str;
    while ((end_pos = str.find('_', begin_pos)) != string::npos) {
      string substr(str, begin_pos, end_pos-begin_pos);
      output += string(substr.rbegin(), substr.rend());
      output += "_";
      begin_pos = end_pos + 1;
    }
    string substr(str, begin_pos, end_pos);
    output += string(substr.rbegin(), substr.rend());

    cout << output << endl;
  }
  return 0;
}
