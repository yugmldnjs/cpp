// 3. Lotto

#include <iostream>
#include <random>
using namespace std;

int main() {
  random_device rd;
  mt19937 gen(rd());
  int a, b, c, d, e, f;

  a = gen() % 45 + 1;

  do {
    b = gen() % 45 + 1;
  } while (a == b);

  do {
    c = gen() % 45 + 1;
  } while (c == a || c == b);

  do {
    d = gen() % 45 + 1;
  } while (d == a || d == b || d == c);

  do {
    e = gen() % 45 + 1;
  } while (e == a || e == b || e == c || e == d);

  do {
    f = gen() % 45 + 1;
  } while (f == a || f == b || f == c || f == d || f == e);

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << e << endl;
  cout << f << endl;

  return 0;
}