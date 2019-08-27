#include <bits/stdc++.h>

using namespace std;

void print() {
  cout << "print\n";
}

typedef void (*Ptf)();

int main() {
  Ptf fun1 = &print;
  Ptf fun2 = print;
  fun1();
  fun2();

  return 0;
}