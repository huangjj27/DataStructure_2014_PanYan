// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1023_simple_hash_2.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1031&cid=1405
// hash map that deal with conflict.
#include <iostream>
#include <string>

#define MAX_SIZE 1000

using std::cin;
using std::cout;
using std::endl;

using std::string;

void Query(int* hash_map, int hash_length, int number) {
  int i;
  for (i = 0;
       hash_map[(number%hash_length + i*i) % hash_length];
       i++) {
    if (hash_map[(number%hash_length + i*i) % hash_length] == number) {
      cout << "yes" << endl;
      return;
    }
  }
  cout << "no" << endl;
}

int main() {
  int hash_length, hash_map[MAX_SIZE + 1] = { 0 };
  cin >> hash_length;

  string operation;

  while (cin >> operation && operation != "End") {
    if (operation == "Add") {
      int new_element;
      cin >> new_element;
      int i;
      for (i = 0;
           hash_map[(new_element%hash_length + i*i)%hash_length];
           i++) {}
      hash_map[(new_element%hash_length + i*i) % hash_length] = new_element;
    } else if (operation == "Query") {
      int number;
      cin >> number;
      Query(hash_map, hash_length, number);
    } else if (operation == "Print") {
      for (int i = 0; i < hash_length; i++) {
        cout << i << "#";
        if (hash_map[i])
          cout << hash_map[i];
        else
          cout << "NULL";
        cout << endl;
      }
    }
  }

  return 0;
}
