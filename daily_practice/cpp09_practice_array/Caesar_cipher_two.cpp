// 1.Caesar cipher two

#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  int key;
  cout << "Input string: ";
  getline(cin, str);
  cout << "Input key: ";
  cin >> key;

  cout << "Cipher string: ";
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      cout << ' ';
      continue;
    }
    if (str[i] + key > 'Z') {
      cout << char(str[i] - 26 + key);
        
    } else {
      cout << char(str[i] + key);
    }
  }

 
}