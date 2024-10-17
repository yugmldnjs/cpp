// 3. Digit three

#include <iostream>
using namespace std;

int stack[1000]={0,};
int ptr = 0;

void push(int data);
int pop();
void digit_three(int number);
void print();

int main() {
  
  int number;
  cout << "Input number: ";
  cin >> number;
  digit_three(number);

  return 0;
}

void push(int data) {
  stack[ptr] = data;
  ptr++;

  return;
}

int pop() {
  ptr--;
  return stack[ptr];
}

void digit_three(int number) {
  while (true) {
    if (number < 1000) {
      push(number);
      break;
    }
    push(number % 1000);
    push(-1);
    number /= 1000;
  }
  print();
  return;
}
void print() {
  while (ptr > 0) {
    int token = pop();
    if (token == -1) {
      cout << ',';
    } else {
      cout << token;
    }
  }
  return;
}