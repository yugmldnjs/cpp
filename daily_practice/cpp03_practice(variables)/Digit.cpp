// 3.Digit

#include <iostream>
using namespace std;

int main() {
  int num, thousands, hundreds, tens, ones;

  cout << "10000이하의 수를 입력하세요: ";
  cin >> num;

  thousands = num / 1000;
  num %= 1000;

  hundreds = num / 100;
  num %= 100;

  tens = num / 10;
  num %= 10;
  ones = num;

  cout << "thousands: " << thousands << endl
       << "hundreds: " << hundreds << endl
       << "tens: " << tens << endl
       << "ones: " << ones << endl;

  return 0;
}