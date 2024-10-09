// 2.Timer

#include <iostream>
using namespace std;

int main() {
  int input_seconds, days, hours, minutes, seconds;

  cout << "Enter the number of seconds: ";
  cin >> input_seconds;
  seconds = input_seconds;
  days = seconds / 86400;
  seconds %= 86400;

  hours = seconds / 3600;
  seconds %= 3600;

  minutes = seconds / 60;
  seconds %= 60;

  cout << input_seconds << " seconds = " << days << " days, " << hours << " hours, "
       << minutes << " minutes, " << seconds << " seconds";

  return 0;
}