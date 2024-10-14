// 2. Discount

#include <iostream>
using namespace std;

int main() {
  int price = 1000;
  int n_item, original_price, discount_price;

  cout << "number of items? ";
  cin >> n_item;

  original_price = n_item * price;
  if (n_item >= 10) {
    discount_price = original_price * 0.9;
    cout << "original price: " << original_price << " KRW" << endl;
    cout << "discount price: " << discount_price << " KRW" << endl;
  } else if (n_item >= 0) {
    cout << "price: " << original_price << " KRW" << endl;
  }

  return 0;
}