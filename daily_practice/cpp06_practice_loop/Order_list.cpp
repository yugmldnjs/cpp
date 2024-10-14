// 1. Order list

#include <iostream>
using namespace std;

int main() {
  
  int menu;
  int bugger = 0;
  int fries = 0;
  int coke = 0;
  cout << "Select a menu (1~4)" << endl;

  do {
    cout << "1) Bugger, 2) Fries, 3) Coke, 4) Finish" << endl;
    cin >> menu;
    switch (menu) {
      case 1:
        cout << "You've ordered a Bugger" << endl;
        bugger++;
        break;
      case 2:
        cout << "You've ordered Fries" << endl;
        fries++;
        break;
      case 3:
        cout << "You've ordered a Coke" << endl;
        coke++;
        break;
      case 4:
        cout << "Your order has been received!" << endl;
        break;
      default:
        cout << "Wrong input" << endl;
        break;
    }
  } while (menu != 4);

  cout << endl<< "Your orders" << endl;
  
  if (bugger) cout << "1) Bugger * " << bugger << endl;
  if (fries) cout << "2) Fries * " << fries << endl;
  if (coke) cout << "3) Coke * " << coke << endl;

  return 0;
}