#include <bits/stdc++.h>

using namespace std;

class A {
 public:
  A() {}
  A(int a) {}
//  static int a = 5;  // error: ISO C++ forbids in-class initialization of non-const static member ‘A::a’
  static int a;
  const static int b = 1;
  int c;
};

//A::a = 3;  // error: ‘a’ in ‘class A’ does not name a type
int A::a = 3;

int main() {
  A oa;
//  A oa(0);  // can be compiled
//  A oa = A();  // the same as "A oa;"
//  int A::a = 2;  // error: qualified-id in declaration before ‘=’ token
//  A::b = 3;  // error: assignment of read-only variable ‘A::b’
  cout << oa.a << endl;
  oa.a = 4;
  cout << A::a << endl;
  cout << A::b << endl;
}
