// 1.Touring the 2D array with a pointer

#include <iostream>
using namespace std;

int main() {
  int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  for (int i = 0; i < sizeof(arr) / sizeof(*(arr + i)); i++) {
    for (int j = 0; j < sizeof(*(arr + i)) / sizeof(int); j++) {
      cout << *(*(arr + i) + j) << " ";
    }
    cout << endl;
  }

  return 0;
}