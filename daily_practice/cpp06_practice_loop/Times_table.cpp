// 2. Times Table

#include <iostream>
using namespace std;

int main() {
  for (int i = 1; i < 10; i++) {
    for (int j = 2; j < 10; j++) {
      printf("%d*%d=%2d ", j, i, j * i);
    }
    cout << endl;
  }

  return 0;
}