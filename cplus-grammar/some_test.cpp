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

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;

    while ((p1 >= 0) && (p2 >= 0))
      nums1[p--] = (nums1[p1] < nums2[p2]) ? nums2[p2--] : nums1[p1--];
    while (p2 >= 0) nums1[p--] = nums2[p2--];

//    for (int i = m + n - 1; i >= 0; --i) {
//      if (p1 < 0 || p2 >= 0 && nums2[p2] > nums1[p1]) nums1[i] = nums2[p2], --p2;
//      else nums1[i] = nums1[p1], --p1;
//    }
  }
};

void func(int **a) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j)
      cout << a[i][j] << " ";
    cout << endl;
  }
}

int main() {
//  TestFunPtr();

  int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  func((int **)a);

  return 0;
}
