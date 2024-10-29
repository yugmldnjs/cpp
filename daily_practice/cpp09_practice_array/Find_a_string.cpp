// 3. Find a string

#include <iostream>
#include <string>
using namespace std;

int isinclude(string str1, string str2) {
  for (int i = 0; i <= str1.length() - str2.length(); i++) {
    bool match = true;

    for (int j = 0; j < str2.length(); j++) {
      if (str1[i + j] != str2[j]) {
        match = false;
        break;
      }
    }
    if (match) {
      return i;
    }
  }
  return -1;
}

int main() {
  string str1, str2;
  cout << "string1: ";
  getline(cin, str1);
  cout << "string2: ";
  getline(cin, str2);

  int idx = isinclude(str1, str2);
  if (idx == -1) {
    cout << "Not found" << endl;
  } else {
    cout << idx << endl;
  }
  return 0;
}
