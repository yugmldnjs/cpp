// 1. Calculator with a class

#include <iostream>
using namespace std;

template <typename T>
class my_calc {
 private:
  T num1, num2;

 public:
  my_calc(T num1, T num2) : num1(num1), num2(num2)
  {}

  T add() { return num1 + num2; }
  T sub() { return num1 - num2; }
  T mul() { return num1 * num2; }
  T div() {
    if (num2 == 0) {
      cout << "Cannot divide by ";
      return num2;
    }
    return num1 / num2;
  }
};

int main() {
  my_calc<int> c(10, 20);

  cout << c.add() << endl;
  cout << c.sub() << endl;
  cout << c.mul() << endl;
  cout << c.div() << endl;
}