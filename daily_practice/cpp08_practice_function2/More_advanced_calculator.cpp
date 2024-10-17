// 1. More advanced calculator

#include <iostream>
using namespace std;

template <typename T>
T calc(T a, T b, char op) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      if (b) return a / b;
      return -1;
    default:
      return -1;
  }
}

int main() {
  double a, b;
  char op;
  double result;

  cout << "--------------" << endl;
  cout << "+ : add" << endl;
  cout << "- : subtract" << endl;
  cout << "* : multiply" << endl;
  cout << "/ : divide" << endl;
  cout << "Q : quit" << endl;
  cout << "--------------" << endl;

  while (true) {
    cout << "Select an operator: ";
    cin >> op;
    if (op == 'Q') {
      cout << "quit" << endl;
      break;
    }

    cout << "Input two number: ";
    cin >> a >> b;

    result = calc(a, b, op);
    if (result == -1) {
      if (op == '/' && b == 0) {
        cout << "Cannot divide by 0" << endl;
      } else {
        cout << "Wrong operator!" << endl;
      }
    } 
    else {
      cout << "Answer: " << calc(a, b, op) << endl<<endl;
    }
  }

  return 0;
}
