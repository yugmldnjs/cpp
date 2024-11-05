// 2.my_memcpy

#include <iostream>
using namespace std;

void* my_memcpy(void* destination, const void* source, size_t num) {
  for (int i = 0; i < num; i++) {
    ((char*)destination)[i] = ((char*)source)[i];
  }
  return destination;
}
int main() {
  char csrc[] = "Hello!";
  char cdst[16];

  int isrc = 12345678;
  int idst;

  my_memcpy(cdst, csrc, sizeof(csrc));
  my_memcpy(&idst, &isrc, sizeof(isrc));

  cout << cdst << endl;
  cout << idst << endl;
}