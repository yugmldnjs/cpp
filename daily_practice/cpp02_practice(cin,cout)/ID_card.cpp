// 2.ID card

#include <iostream>

using namespace std;

int main() {
  int student_num;
  string first_name, second_name, name;

  cout << "Your student number: ";
  cin >> student_num;
  cout << "Your first name: ";
  cin >> first_name;
  cout << "Your second name: ";
  cin >> second_name;

  name = first_name + " " + second_name;

  cout << "My name is " << name << "." << endl
       << "My student ID is " << student_num << "." << endl
       << "My name and ID is " << name << " and " << student_num << "." << endl;
  return 0;
}