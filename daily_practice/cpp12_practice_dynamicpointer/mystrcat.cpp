// 1. mystrcat

#include <iostream>
using namespace std;

char* mystrcat(const char* str1, const char* str2);

int main() {
  char* str = mystrcat("Hello!", "World!");
  cout << "Result:" << endl;
  cout << str << endl;

  return 0;
}

char* mystrcat(const char* str1, const char* str2) {
  int len1;
  for (len1 = 0; str1[len1] != '\0'; len1++);
  int len2;
  for (len2 = 0; str2[len2] != '\0'; len2++);

  char* result = new char[len1 + len2 + 1];

  for (int i = 0; i < len1; i++) {
    result[i] = str1[i];
  }
  for (int i = 0; i < len2; i++) {
    result[len1 + i] = str2[i];
  }
  result[len1 + len2] = '\0';

  return result;
}
