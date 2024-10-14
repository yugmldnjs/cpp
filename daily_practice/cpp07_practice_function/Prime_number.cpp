// 2. Prime number

#include <iostream>
using namespace std;

bool isPrime(int n);

int main() {
  int n;
  while (1) {
    cout << "input number: ";
    cin >> n;
    if (n == -1) {
      cout << "Done" << endl;
      break;
    }

    if (isPrime(n)) {
      cout << n << " is a prime number." << endl << endl;
    } else {
      cout << n << " is not a prime number." << endl << endl;
    }
  }

  return 0;
}

bool isPrime(int n) {
  if (n == 1 || (n % 2 == 0)) return false;

  int half_n = n / 2;
  while (half_n > 1) {
    if (n % half_n == 0) return false;
    half_n--;
  }
  return true;
}