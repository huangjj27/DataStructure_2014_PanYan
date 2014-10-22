// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1021_linked_list_hash.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1031&cid=1405
// hash map with hash(key) = key mod 13.
#include <iostream>
#include <vector>

#define MAX_SIZE 13

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main() {
  int n = 0;  // the count of numbers

  while (cin >> n && n) {
    vector<int> hash_map[MAX_SIZE + 1];
    for (int i = 0, number = 0; i < n; i++) {
      cin >> number;
      hash_map[number % 13].push_back(number);
    }

    for (int i = 0; i < MAX_SIZE; i++) {
      cout << i << "#";
      if (hash_map[i].empty()) {
        cout << "NULL";
      } else {
        for (vector<int>::iterator it = hash_map[i].begin();
             it != hash_map[i].end();
             it++) {
          if (it != hash_map[i].begin()) cout << " ";
          cout << *it;
        }
      }
      cout << endl;
    }
  }

  return 0;
}
