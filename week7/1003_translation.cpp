// Copyright (c) Junjie_Huang@SYSU(SNO:1331087). All Rights Reserved.
// 1003_translation.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1003&cid=1567
#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::getline;

using std::string;
using std::map;
using std::pair;

int main() {
  string str, english, foreign;
  map<string, string> translation;
  while (getline(cin, str) && str != "") {
    size_t pos = str.find(" ");
    english.assign(str, 0, pos - 0);
    foreign.assign(str, pos + 1, str.size() - pos);
    translation[foreign] = english;
  }
  while (cin >> foreign) {
    if (translation[foreign] == "")
      cout << "eh" << endl;
    else
      cout << translation[foreign] << endl;
  }
  return 0;
}
