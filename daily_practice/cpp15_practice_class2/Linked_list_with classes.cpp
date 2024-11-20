// 1. Linked list with classes
#include <iostream>
using namespace std;

struct node {
  int data;
  node* next;

  node(int data) : data(data), next(0) {}
};

class my_list {
  node* head;
  node* tail;
  node* current;

 public:
  my_list() : head(nullptr), tail(nullptr), current(nullptr) {}

  my_list& append(int data) {
    if (tail == nullptr) {
      head = tail = current = new node(data);
    } else {
      tail->next = new node(data);
      tail = tail->next;
    }
    return *this;
  }  // add a new element to the list

  my_list& next() {
    current = current->next;
    return *this;
  }  // move to the next element in the list

  int get() {
    return current->data;
  }  // return the value of the current position

  void rewind() {
    current = head;
  }  // reset the current position to the first of the list.

  void info() {
    cout << "length: " << length(head, tail)
         << ", current: " << length(head, current)<<endl;
  }  // print out the length of the list and the current position.

  // 처음부터 지정 위치까지의 리스트 길이 반환
  int length(node* start, node* end) {
    int cnt = 0;
    if (start == end) return 0;
    while (start != end) {
      start = start->next;
      cnt++;
    }
    cnt++;
    return cnt;
  }
};

int main(){
  my_list l;

  l.append(10).append(20).append(30).append(40);
;
  l.next().next();
  cout << l.get() << endl;

  l.info();

  l.rewind();
  cout << l.get() << endl;
}
