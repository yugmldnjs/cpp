// 2.New linked list

#include <iostream>
using namespace std;

struct node {
  int data;
  node* next;
  int index;

  node(int i, node* n, int in) : data(i), next(n), index(in) {}
};

class slist {
 private:
  node* head;
  node* tail;
  node* current;
  int index;

 public:
  slist() : head(0), current(0), index(0) {}

  void push_front(int i) {
    head = new node(i, head, index++);
    if (head->next == 0) current = tail = head;
  }

  void push_back(int i) {
    if (head == 0) {
      head = current = tail = new node(i, 0, index++);
    } else {
      tail->next = new node(i, 0, index++);
      tail = tail->next;
    }
  }

  void next() { current = current->next; }

  int get() { return current->data; }

  int get_size() { return index; }

  int operator[](int i) {
    node* s;
    for (s = head; s->index != i; s = s->next);
    return s->data;
  }
};

int main() {
  slist s;
  s.push_back(10);
  s.push_back(20);
  s.push_back(30);
  s.push_back(40);
  s.push_front(50);
  s.push_front(60);
  s.push_front(70);
  s.push_front(80);
  for (int i = 0; i < s.get_size(); i++) {
    cout << i << ": " << s[i] << endl;
  }
  cout << s.get();
}