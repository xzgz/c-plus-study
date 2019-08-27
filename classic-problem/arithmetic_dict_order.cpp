#include <bits/stdc++.h>

using namespace std;

/*
 * 题目描述：
 * 一个算术表达式，只由加、减、乘、除四种运算符和整数构成，没有括号。
 * 现在可以无限次地交换相邻的2个数字，使表达式的值不变。请求出字典序
 * 最小的一个表达式并打印出来。
 * 输入描述：
 * 第一行是一个数字n，表示算术表达式中数字的个数，运算符的个数为n-1，
 * 运算符和数字之间用一个空格隔开。1<=n<=1000，数字的绝对值小于等于
 * 1000。第二行是这个算术表达式。
 * 示例输入：
 * 6
 * 3 + 2 + 1 + -4 * -5 + 1
 * 示例输出：
 * 1 + 2 + 3 + -5 * -4 + 1
 */
int main() {
  int n;
  string line;
  getline(cin, line);
  n = stoi(line);
  vector<int> nums(n);
  vector<char> symbol(n-1);
  getline(cin, line);
  string::iterator loc;
  long order;
  for (int i = 0; i < 2*(n-1); ++i) {
    if (i % 2) {
      loc = find(line.begin(), line.end(), ' ');
      order = distance(line.begin(), loc);
      symbol[i / 2] = *(loc - 1);
      line.erase(0, 1 + order);
    } else {
      loc = find(line.begin(), line.end(), ' ');
      order = distance(line.begin(), loc);
      nums[i / 2] = stoi(line.substr(0, order));
      line.erase(0, 1 + order);
    }
  }
  nums[n-1] = stoi(line);
  sort(nums.begin(), nums.begin());

  vector<int>::iterator ib, ie;
  for (;;) {
    int i = 0;
    int j;
    ie = ib;
    if (symbol[i] == '+') {
      ib = nums.begin() + i;
      ie = ib;
      j = i + 1;
      for (; j < n-1; ++j) {
        ++ie;
        if (symbol[j] != '+') break;
      }
      if (j == n-1) ie += 2;
      if (symbol[j] == '-') ie += 1;
      sort(ib, ie);
    }
    if (symbol[i] == '*') {
      ib = nums.begin() + i;
      ie = ib;
      j = i + 1;
      for (; j < n-1; ++j) {
        ++ie;
        if (symbol[j] != '*') break;
      }
      if (j == n-1) ie += 2;
      else ie += 1;
      sort(ib, ie);
    }
    if (ie - ib > 0) i += ie - ib;
    else i += 1;
    if (i == n) break;
  }

  for (int i = 0; i < n-1; ++i) {
    cout << nums[i] << ' ' << symbol[i] << ' ';
  }
  cout << nums[n-1];

  return 0;
}
