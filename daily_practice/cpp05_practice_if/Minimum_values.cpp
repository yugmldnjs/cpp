// 4. Minimum value

#include <iostream>
using namespace std;

int main() {
  int num1, num2, num3;
  cout << "Input numbers: ";
  cin >> num1 >> num2 >> num3;

  int min;
  if ((num1 <= num2) && (num1 <= num3)) {
    min = num1;
  } else if ((num2 <= num1) && (num2 <= num3)) {
    min = num2;
  } else if ((num3 <= num1) && (num3 <= num1)) {
    min = num3;
  }
  cout << "minimum number: " << min << endl;

  return 0;
}