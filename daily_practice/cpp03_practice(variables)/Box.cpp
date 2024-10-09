// 1.Box
// answer: usigned short type »ç¿ë

#include <iostream>
using namespace std;

int main() {
  unsigned short length, width, height, volume;

  cout << "Input length: ";
  cin >> length;
  cout << "Input width: ";
  cin >> width;
  cout << "Input height: ";
  cin >> height;

  volume = length * width * height;

  cout << "Box volume: " << volume << endl;


  return 0;
}