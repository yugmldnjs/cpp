// 3.Digits two

#include <iostream>
using namespace std;

int main() {
  enum int_to_word {
    zero = 0,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine
  };

  int num;

  cout << "Input your number: ";
  cin >> num;

  int thousands = num / 1000;
  int hundreds = (num % 1000) / 100;
  int tens = (num % 100) / 10;
  int ones = num % 10;

  cout << "thousands: ";
  switch (thousands) {
    case zero:
      cout << "zero" << endl;
      break;
    case one:
      cout << "one" << endl;
      break;
    case two:
      cout << "two" << endl;
      break;
    case three:
      cout << "three" << endl;
      break;
    case four:
      cout << "four" << endl;
      break;
    case five:
      cout << "five" << endl;
      break;
    case six:
      cout << "six" << endl;
      break;
    case seven:
      cout << "seven" << endl;
      break;
    case eight:
      cout << "eight" << endl;
      break;
    case nine:
      cout << "nine " << endl;
      break;
  }
  cout << "hundreds: ";
  switch (hundreds) {
    case zero:
      cout << "zero" << endl;
      break;
    case one:
      cout << "one" << endl;
      break;
    case two:
      cout << "two" << endl;
      break;
    case three:
      cout << "three" << endl;
      break;
    case four:
      cout << "four" << endl;
      break;
    case five:
      cout << "five" << endl;
      break;
    case six:
      cout << "six" << endl;
      break;
    case seven:
      cout << "seven" << endl;
      break;
    case eight:
      cout << "eight" << endl;
      break;
    case nine:
      cout << "nine " << endl;
      break;
  }
  cout << "tens: ";
  switch (tens) {
    case zero:
      cout << "zero" << endl;
      break;
    case one:
      cout << "one" << endl;
      break;
    case two:
      cout << "two" << endl;
      break;
    case three:
      cout << "three" << endl;
      break;
    case four:
      cout << "four" << endl;
      break;
    case five:
      cout << "five" << endl;
      break;
    case six:
      cout << "six" << endl;
      break;
    case seven:
      cout << "seven" << endl;
      break;
    case eight:
      cout << "eight" << endl;
      break;
    case nine:
      cout << "nine " << endl;
      break;
  }
  cout << "ones: ";
  switch (ones) {
    case zero:
      cout << "zero" << endl;
      break;
    case one:
      cout << "one" << endl;
      break;
    case two:
      cout << "two" << endl;
      break;
    case three:
      cout << "three" << endl;
      break;
    case four:
      cout << "four" << endl;
      break;
    case five:
      cout << "five" << endl;
      break;
    case six:
      cout << "six" << endl;
      break;
    case seven:
      cout << "seven" << endl;
      break;
    case eight:
      cout << "eight" << endl;
      break;
    case nine:
      cout << "nine " << endl;
      break;
  }
  return 0;
}