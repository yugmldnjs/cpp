// 2. Quadrant two

#include <cmath>
#include <iostream>
using namespace std;

double dist_2d() {
  int x1, y1, x2, y2;
  cout << "input x1 y1: ";
  cin >> x1 >> y1;
  cout << "input x2 y2: ";
  cin >> x2 >> y2;
  double dist = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));
  return dist;
}

int main() {
  double dist = dist_2d();
  cout << "Distance: " << dist;
  return 0;
}