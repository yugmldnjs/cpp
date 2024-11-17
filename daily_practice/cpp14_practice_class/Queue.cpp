// 2. Queue

#include <iostream>
using namespace std;

template <typename T>
struct list {
  T data;
  list *next = NULL;
};

template <typename T>
class my_queue {
  list<T> *head;
  list<T> *tail;

 public:
  my_queue();
  void Enqueue(T data);
  T Dequeue();
  T Peek();
};

template <typename T>
my_queue<T>::my_queue() : head(NULL), tail(NULL) {}

template <typename T>
void my_queue<T>::Enqueue(T data) {
  list<T> *p = new list<T>;
  p->data = data;

  if (head == NULL) {
    head = tail = p;
  } else {
    tail->next = p;
    tail = p;
  }
}

template <typename T>
T my_queue<T>::Dequeue() {
  T result = Peek();
  head = head->next;

  if (head == NULL) {
    tail = NULL;
  }
  return result;
}

template <typename T>
T my_queue<T>::Peek() {
  return head->data;
}

int main() {
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
