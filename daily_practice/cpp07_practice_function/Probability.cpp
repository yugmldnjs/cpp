// 4. Probability

#include <iostream>
#include <random>
using namespace std;

int count1, count2, count3, count4, count5, count6;

void graph(int len, int dot);
void count(int num);

int main() {
 
  int n;
  cout << "Roll a dice 'n' times: ";
  cin >> n;
  
  count(n);
  
  cout << "1: ";  graph(n, count1);
  cout << "2: ";  graph(n, count2);
  cout << "3: ";  graph(n, count3);
  cout << "4: ";  graph(n, count4);
  cout << "5: ";  graph(n, count5);
  cout << "6: ";  graph(n, count6);

  return 0;
}

 void graph(int len, int dot) {
  for (int i = 0; i < len; i++) {
    if (i < dot)
      cout << "@";
    else
      cout << "*";
  }
  cout << endl;
}

void count(int num) {
  random_device rd;
  mt19937 gen(rd());

  count1 = count2 = count3 = count4 = count5 = count6 = 0;

  for (int i = num; i > 0; i--) {
    int r = gen() % 6 + 1;

    switch (r) {
      case 1: count1++; break;
      case 2: count2++; break;
      case 3: count3++; break;
      case 4: count4++; break;
      case 5: count5++; break;
      case 6: count6++; break;
    }
  }
}