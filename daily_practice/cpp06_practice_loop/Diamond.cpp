// 4. Diamond

#include <iostream>
using namespace std;

int main() {
  int height;
  cout << "input height: ";
  cin >> height;
  int mid = height / 2;
  int i, j, k;
  
  for (i = 0; i < mid; i++) {
    for (j = i; j < mid; j++) { 
      cout << " ";
    }
    for (k = 0; k < i * 2 + 1; k++) cout << "*";
    cout << endl;
  }

  if (height % 2) {
    for (i = 0; i < height; i++) {
      cout << "*";
    }
    cout << endl;
  }

  for (i = mid; i > 0; i--) {
    for (j = 0; j < mid-i+1; j++) {
      cout << " ";
    }
    for (k = 0; k < i * 2-1; k++) {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}