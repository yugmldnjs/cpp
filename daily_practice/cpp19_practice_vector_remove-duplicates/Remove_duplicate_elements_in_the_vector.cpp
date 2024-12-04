// 1. Remove duplicate elements in the vector
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  vector<char> v{'a', 'b', 'b', 'a', 'e', 'd', 'd', 'b'};

  for (auto i : v) cout << i << " ";
  cout << endl;  // a b b a e d d b
  sort(v.begin(), v.end());

  v.erase(unique(v.begin(), v.end()), v.end());

  for (auto i : v) cout << i << " ";

  cout << endl;  // a b d e
}