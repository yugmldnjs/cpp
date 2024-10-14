// 3. ipower

#include <iostream>
using namespace std;

void ipower(int n);

int main() {
  int n;
  cout << "input number: ";
  cin >> n;
  ipower(n);

  return 0;
}

void ipower(int n) {
  int sqaure_n;
  for (int i = 0; i < 11; i++) {
    if (i) {
      sqaure_n *= n;
    } else {
      sqaure_n = 1;
    }
    cout << n << "^" << i << " = " << sqaure_n << endl;
  }
}