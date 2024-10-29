// 2. Quite advanced calculator

#include <iostream>
using namespace std;

void matrix_mul(int matrix1[][3], int matrix2[][3]);
void matrix_sum(int matrix1[][3], int matrix2[][3]);

int main() {
  char op;
  int matrix1[3][3];
  int matrix2[3][3];
  cout << "------------------" << endl
       << "+ : addition" << endl
       << "* : multiplication" << endl
       << "------------------" << endl;
  cout << "Selet an  operator: ";
  cin >> op;
  cout << "Input matrix1: ";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> matrix1[i][j];
    }
  }
  cout << "Input matrix2: ";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> matrix2[i][j];
    }
  }
  if (op == '+') matrix_sum(matrix1, matrix2);
  else if (op == '*') matrix_mul(matrix1, matrix2);

  return 0;
}

void matrix_mul(int matrix1[][3], int matrix2[][3]) {
  int result[3][3] = {0.};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][i];
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}

void matrix_sum(int matrix1[][3], int matrix2[][3]) {
  int result[3][3] = {0.};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}
