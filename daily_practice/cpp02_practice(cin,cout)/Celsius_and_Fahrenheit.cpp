// 5.Celsius and Fahrenheit

#include <iostream>

using namespace std;

int main() {
  int celsius;
  double fahrenheit;

  cout << "Celsius value: ";
  cin >> celsius;

  fahrenheit = 1.8 * celsius + 32.0;
  cout << celsius << " degrees Celsius is " << fahrenheit
       << " degrees Fahrenheit.";
  return 0;
}