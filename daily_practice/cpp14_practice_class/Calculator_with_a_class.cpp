// 1. Calculator with a class

#include <iostream>
using namespace std;

class my_calc {
 private:
  int num1, num2;

 public:
  my_calc(int n1, int n2) : num1(n1), num2(n2) {}

  int add() { return num1 + num2; }
  int sub() { return num1 - num2; }
  int mul() { return num1 * num2; }
  int div() {
    if (num2 != 0) return num1 / num2;
  }
};

int main() {
  my_calc c(10, 0);

  cout << c.add() << endl;
  cout << c.sub() << endl;
  cout << c.mul() << endl;
  cout << c.div() << endl;
}