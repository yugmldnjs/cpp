// 1. Queue version 2
#include <iostream>
#include <vector>

using namespace std;

class my_queue : private vector<int> {
  vector<int> v;

 public:
  void enqueue(int data) { v.push_back(data); }

  int dequeue() {
    int result = *v.begin();
    v.erase(v.begin(), v.begin() + 1);
    return result;
  }

  int peek() { return *v.begin(); }
};

int main()

{
  my_queue q;

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);

  cout << q.peek() << endl;  // 10
  q.dequeue();
  cout << q.peek() << endl;  // 20
  q.dequeue();
  cout << q.peek() << endl;  // 30
  q.dequeue();
  cout << q.peek() << endl;  // 40
  q.dequeue();
}