// 2. Reverse linked list

#include <iostream>
using namespace std;

struct list {
  int value;
  list *next = NULL;
};

list *append(list *p, int value);
list *append(int value);
list *reverse(list *head);

int main() {
  list *head;
  list *loop;
  list *tail;
  list *r_head;
  tail = head = append(10);
  tail = append(tail, 20);
  tail = append(tail, 30);
  tail = append(tail, 40);

  cout << "Result" << endl;
  for (loop = head; loop != NULL; loop = loop->next) {
    cout << loop->value << endl;
  }
  cout << endl;

  r_head = reverse(head);

  cout << "Reversed" << endl;
  for (loop = r_head; loop != NULL; loop = loop->next) {
    cout << loop->value << endl;
  }
}

list *append(list *p, int value) {
  list *q = new list;
  q->value = value;
  p->next = q;
  return q;
}

list *append(int value) {
  list *q = new list;
  q->value = value;
  return q;
}

list *reverse(list *head) {
  list *p = NULL;
  list *n;

  while (head != NULL) {
    n = head->next;
    head->next = p;
    p = head;
    head = n;
  }

  return p;
}