#include <bits/stdc++.h>

using namespace std;

typedef void (*Ptf)();

void print() {
  cout << "print\n";
}

void TestFunPtr() {
  Ptf fun1 = &print;
  Ptf fun2 = print;
  fun1();
  fun2();
}

int main() {
//  TestFunPtr();
  int a, b;
  a = 5;
  while (a--) cout << a << endl;

  return 0;
}
