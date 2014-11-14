// Copyright (c) 2014 by Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1000_binary_search.h: DataStructure2014@PanYan
// http://soj.me/viewsource.php?cid=1567&sid=1942862
// the function search in an ordered vector table between bot and top
// (inclusive) for x.It returns the index of its
// last oocurrence if search is successful,
// it returns - 1 if search is unsuccessful.
// and the question requires us to search the final position.
template <typename T>
int binarySearch(const vector<T> table, int bot, int top, const T &x) {
  while (bot <= top) {
    int mid = (bot + top) / 2;
    if (x == table[mid]) {
      while (table[mid] == table[mid + 1]) mid++;
      return mid;
    } else if (x < table[mid]) {
      top = mid - 1;
    } else if (x > table[mid]) {
      bot = mid + 1;
    }
  }
  return -1;
}
