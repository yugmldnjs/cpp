// 1. Upgrade the Linked list class
#include <iostream>
using namespace std;

struct node {
  int data;
  node* next;
  int index;

  node(int data, int index) : data(data), index(index), next(0) {}
};

class my_list {
 private:
  node* head;
  node* tail;
  node* current;
  int index;

 public:
  my_list() : head(nullptr), tail(nullptr), current(nullptr), index(0) {}

  my_list& append(int data) {
    if (tail == nullptr) {
      head = tail = current = new node(data, index++);
    } else {
      tail->next = new node(data, index++);
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

  my_list& rewind() {
    current = head;
    return *this;
  }  // reset the current position to the first of the list.

  void info() {
    cout << "length: " << index << ", current: " << current->index << endl;
  }  // print out the length of the list and the current position.

  void set_index(node* start, int i) {
    for (i; start != nullptr; i++) {
      start->index = i;
      start = start->next;
    }
  }

  node* get_head() { return head; }
  node* get_tail() { return tail; }
  int get_length() { return index; }

  void printall() {
    node* tmp = head;
    while (tmp != nullptr) {
      cout << tmp->index << ": " << tmp->data << endl;
      tmp = tmp->next;
    }
  }

  my_list& operator+(int data) {
    append(data);
    return *this;
  }  // append as an operator

  my_list& operator+(my_list& list) {
    tail->next = list.get_head();
    tail = list.get_tail();
    set_index(list.get_head(), index);
    index += list.get_length();
    return *this;
  }  // concatenate a list

  my_list& operator-(int n) {
    node* prev = head;
    if (n == 0) {
      head = head->next;
    } else {
      while (prev->index != n - 1) {
        prev = prev->next;
      }
     
      prev->next = prev->next->next;
    }
    set_index(prev->next, n);
    return *this;
  }  // remove a 'n'-th node
};

int main() {
  my_list l;
  my_list ll;

  l.append(10).append(20).append(30).append(40);

  l.next().next();
  cout << l.get() << endl;  // print out 30

  ll = ll + 100 + 200 + 300;  // append values 100, 200 and 300 to ll.

  ll.next();
  cout << ll.get() << endl;  // print out 200

  ll = ll + l;  // concatenate the list 'l' to the list 'll';
  ll.next().next().next();
  cout << ll.get() << endl;  // print out 20
  ll.info();
  ll.printall();


  ll = ll - 5;  // remove the 5-th node.

  ll.next();
  cout << ll.get() << endl;  // print out 40, not 30.

  ll.printall();
}