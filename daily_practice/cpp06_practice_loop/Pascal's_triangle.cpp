// 5. Pascal's triangle

#include <iostream>
using namespace std;

int main() {
  int height;  // �ﰢ�� ����
  cout << "input height: ";
  cin >> height;
  int nf, rf, nrf;

  for (int n = 0; n < height; n++) {
    nf = 1;
    for (int i = n; i < height; i++) {
      cout << " ";
    }
    // n! ���
    for (int i = 1; i < n + 1; i++) {
      if (n != 0) {
        nf *= i;
      }
    }

    for (int r = 0; r <= n; r++) {
      rf = nrf = 1;
      // r! ���
      for (int j = 1; j < r + 1; j++) {
        if (r != 0) {
          rf *= j;
        }
      }
      // (n-r)! ���
      for (int k = n - r; k >= 0; k--) {
        if (k != 0) {
          nrf *= k;
        }
      }
      cout << nf / (rf * nrf) << " ";
    }

    cout << endl;
  }

  return 0;
}