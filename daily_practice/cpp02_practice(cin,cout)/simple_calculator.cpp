// 1.Simple calculator

#include <iostream>

using namespace std;

int main() {
  int num1;
  int num2;

  cout << "number1: ";
  cin >> num1;
  cout << "number2: ";
  cin >> num2;

  cout << "Add: " << num1 + num2 << endl
       << "Sub: " << num1 - num2 << endl
       << "Mul: " << num1 * num2 << endl
       << "Div: " << num1 / num2 << endl;

  return 0;
}