// 2. Queue

#include <iostream>
using namespace std;

template <typename T>
class my_queue {
  struct list {
    T data;
    list *next = NULL;
  };
  list *head;
  list *tail;

 public:
  my_queue() { head = tail = NULL; }

  void Enqueue(T data) {
    list *p = new list;
    p->data = data;

    if (head == NULL) {
      head = tail = p;
    } else {
      tail->next = p;
      tail = p;
    }
  }

  T Dequeue() {
    T result = Peek();
    head = head->next;

    if (head == NULL) {
      tail = NULL;
    }
    return result;
  }

  T Peek() { return head->data; }
};

int main()

{
  my_queue<int> q;

  q.Enqueue(10);
  q.Enqueue(20);
  q.Enqueue(30);
  cout << "front element: " << q.Peek() << endl;
  cout << q.Dequeue() << endl;
  cout << q.Dequeue() << endl;
  cout << q.Dequeue() << endl;

  my_queue<string> p;
  p.Enqueue("A");
  p.Enqueue("B");
  p.Enqueue("c");
  cout << "front element: " << p.Peek() << endl;
  cout << p.Dequeue() << endl;
  cout << p.Dequeue() << endl;
  cout << p.Dequeue() << endl;
}