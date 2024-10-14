// 1. Advanced calculator

#include <iostream>
using namespace std;

int main() {
  char opr;
  int num1, num2;

  cout << "Select an operator: ";
  cin >> opr;
  if (opr == 'Q') {
    return 0;
  }

  cout << "Input two number: ";
  cin >> num1 >> num2;
  if (cin.fail()) {
    cout << "type error" << endl;
    return 0;
  }

  switch (opr) {
    case '+':
      cout << "Answer: " << num1 + num2 << endl;
      break;
    case '-':
      cout << "Answer: " << num1 - num2 << endl;
      break;
    case '*':
      cout << "Answer: " << num1 * num2 << endl;
      break;
    case '/':
      if (num2 == 0) {
        cout << "Answer: Cannot divide by 0" << endl;
        break;
      } else {
        cout << "Answer: " << num1 / num2 << endl;
        break;
      }
  }

  return 0;
}