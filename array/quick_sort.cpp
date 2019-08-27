#include <bits/stdc++.h>

using namespace std;

void QuickSort(vector<int>& v, int low, int high) {
  if (low >= high)		// 结束标志
    return;
  int first = low;		// 低位下标
  int last = high;		// 高位下标
  int key = v[first];		// 设第一个为基准

  while (first < last)
  {
    // 将比第一个小的移到前面
    while (first < last && v[last] >= key)
      last--;
    if (first < last)
      v[first++] = v[last];

    // 将比第一个大的移到后面
    while (first < last && v[first] <= key)
      first++;
    if (first < last)
      v[last--] = v[first];
  }
  v[first] = key;
  QuickSort(v, low, first - 1);
  QuickSort(v, first + 1, high);
}

void QuickSort2(vector<int>& v, int low, int high) {
  if (low >= high) return;
  int first = low;
  int last = high;
  int key = v[first];

  while (first < last) {
    while (first < last && v[last] >= key) last--;
    if (first < last) v[first++] = v[last];

    while (first < last && v[first] <= key) first++;
    if (first < last) v[last--] = v[first];
  }
  v[first] = key;
  QuickSort2(v, low, first-1);
  QuickSort2(v, first+1, high);
}

int main() {
  vector<int> array = { 5, 7, 1, 3, 2, 7 };
  QuickSort(array, 0, array.size()-1);
//  QuickSort2(array, 0, array.size()-1);
  for (int e : array) {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}
