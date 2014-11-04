// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week5/1000_list.h: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1000&cid=1523
#ifndef LIST_H_
#define LIST_H_

enum Error_code {
  success,
  underflow,
  overflow

};

template <class List_entry>
struct Node {
  List_entry entry;
  Node<List_entry> *next;

};

template <class List_entry>
class MyList {
 public:
  MyList() {
    head = new Node<List_entry>;
    count = 0;
    curPosition = 0;
    current = head;
  }
  ~MyList() {
    this->clear();
    delete head;
  }
  // 拷贝构造函数和赋值运算符重载，注意深拷贝与浅拷贝的差异
  MyList(const MyList<List_entry> &copy) {
    head = new Node<List_entry>;
    count = 0;
    curPosition = 0;
    current = head;
    *this = copy;
  }
  void operator=(const MyList<List_entry> &copy) {
    this->clear();
    this->head = new Node<List_entry>;
    this->head->next = NULL;
    this->count = 0;
    this->curPosition = 0;
    this->current = head;
    int remain = copy.count;
    if (remain != 0) {
      Node<List_entry> *temp = copy.head->next;
      for (int i = 0; i < remain; i++, temp = temp->next) {
        this->insert(i, temp->entry);
      }
    }
  }

  // 清空list
  // 注意这里只能删除元素，不能动表头！
  void clear() {
    for (; count != 0; count--) {
      Node<List_entry> *temp = head;
      head = head->next;
      delete temp;
    }
    count = 0;
    curPosition = 0;
    current = head;
  }

  // 判断list是否为空
  bool empty() const { return !count; }

  // 判断list是否已满
  bool full() const { return false; }

  // 获取list的元素数量
  int size() const { return count; }

  // 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，依次类推
  // 若position < 0 或者 position > count，则返回underflow
  Error_code insert(int position, const List_entry &entry) {
    if (position < 0) return underflow;
    if (position > count) return underflow;

    Node<List_entry>* new_entry = new Node<List_entry>;
    new_entry->entry = entry;
    new_entry->next = NULL;
    if (curPosition <= position) {
      Node<List_entry>* temp = current;
      for (; curPosition < position; curPosition++) temp = temp->next;
      new_entry->next = temp->next;
      temp->next = new_entry;
    } else {
      Node<List_entry>* temp = this->head;
      for (int i = 0; i < position; i++) temp = temp->next;
      new_entry->next = temp->next;
      temp->next = new_entry;
    }

    setPosition(position);
    count++;
    return success;
  }

  // 删除第position个位置的元素，并将该元素的值保存在entry中
  // 若position < 0 或者 position >= count，则返回underflow
  Error_code remove(int position, List_entry &entry) {
    if (position < 0) return underflow;
    if (position >= count) return underflow;

    if (curPosition <= position) {
      Node<List_entry>* temp = current;
      for (; curPosition < position; curPosition++) temp = temp->next;
      Node<List_entry>* toDelete = temp->next;
      temp->next = toDelete->next;
      entry = toDelete->entry;
      delete toDelete;
    } else {
      Node<List_entry>* temp = this->head;
      for (int i = 0; i < position; i++) temp = temp->next;
      Node<List_entry>* toDelete = temp->next;
      temp->next = toDelete->next;
      entry = toDelete->entry;
      delete toDelete;
    }

    count--;
    setPosition(position);
    return success;
  }

  // 获取第position个位置的元素，保存在entry中
  // 若position < 0 或者 position >= count，则返回underflow
  Error_code retrieve(int position, List_entry &entry) const {
    if (position < 0) return underflow;
    if (position >= count) return underflow;

    if (curPosition <= position) {
      Node<List_entry>* temp = current;
      for (; curPosition < position; curPosition++) temp = temp->next;
      entry = temp->next->entry;
    } else {
      Node<List_entry>* temp = this->head;
      for (int i = 0; i < position; i++) temp = temp->next;
      entry = temp->next->entry;
    }
    setPosition(position);
    return success;
  }

  // 将第position个位置的元素替换为entry
  // 若position < 0 或者 position >= count，则返回underflow
  Error_code replace(int position, const List_entry &entry) {
    if (position < 0) return underflow;
    if (position >= count) return underflow;

    if (curPosition <= position) {
      Node<List_entry>* temp = current;
      for (; curPosition < position; curPosition++) temp = temp->next;
      temp->next->entry = entry;
    } else {
      Node<List_entry>* temp = this->head;
      for (int i = 0; i < position; i++) temp = temp->next;
      temp->next->entry = entry;
    }
    setPosition(position);
    return success;
  }

  // 用visit函数遍历list内所有的元素
  void traverse(void(*visit)(List_entry &)) {
    if (head == NULL) return;
    Node<List_entry>* temp = this->head->next;
    for (int i = 0; i < count; i++, temp = temp->next) {
      (*visit)(temp->entry);
    }
  }

 protected:
  int count;                // 记录list内元素数量
  Node<List_entry> *head;   // 链表头指针
  mutable int curPosition;  // current指针的位置编号
  mutable Node<List_entry> *current;  // current指针

  // 设置current指针的位置，指向第position个位置
  void setPosition(int position) const {
    Node<List_entry>* temp = this->head;
    int i = 0;
    for (; i < position; i++)
      temp = temp->next;
    curPosition = i;
    current = temp;
  }
};

#endif
