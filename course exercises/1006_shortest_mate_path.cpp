// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// 1006_shortest_mate_path.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1006&cid=1405
// BFS algorithm
#include <iostream>
#include <queue>

#define max_size 31

using std::cin;
using std::cout;
using std::endl;


class Point {
 public:
  Point() { count_ = 1; }
  Point(int x, int y, int count = 1) {
    x_ = x;
    y_ = y;
    count_ = count;
  }

  Point operator+(const Point &another) {
    Point result(this->x_ + another.x_,
                 this->y_ + another.y_,
                 this->count_ + another.count_);
    return result;
  }
  bool operator==(const Point& another) {
    return (this->x_ == another.x_) && (this->y_ == another.y_);
  }

  int x_;
  int y_;
  int count_;
};

const Point direction[4] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
bool maze[max_size][max_size] = { 0 };

bool isLegal(const int size, const Point& point) {
  if ((0 <= point.x_ && point.x_ < size) &&
      (0 <= point.y_ && point.y_ < size) &&
      maze[point.x_][point.y_] == 0) {
    return true;
  } else {
    return false;
  }
}

int BFS(bool maze[][max_size], int maze_size,
        const Point& begin, const Point& end) {
  std::queue<Point> que;
  que.push(begin);
  maze[begin.x_][begin.y_] = true;

  while (!que.empty()) {
    Point top(que.front());
    que.pop();

    if (top == end) {
      return top.count_;
    } else {
      for (int i = 0; i < 4; i++) {
        Point next = top + direction[i];
        if (isLegal(maze_size, next)) {
          maze[next.x_][next.y_] = true;
          que.push(next);
        }
      }
    }
  }
  return 0;
}

int main() {
  int N;
  while (cin >> N && N) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) cin >> maze[i][j];
    }
    Point begin(0, 0), end(N - 1, N - 1);
    cout << BFS(maze, N, begin, end) << endl;
  }
  return 0;
}
