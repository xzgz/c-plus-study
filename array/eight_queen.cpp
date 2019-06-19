#include <bits/stdc++.h>

using namespace std;

/*
题目：八皇后问题
问题描述：在8X8的国际象棋上摆放八个皇后，使其不能相互攻击，即任意两个皇后不得处于同一行，
同一列或者同一对角线上，求出所有符合条件的摆法。
思路：任意两个皇后不得处于同一行，由此可得每个皇后都单独占据一行。
我们可以定义一个数组ColumnIndex[8]，其中ColumnIndex[i]表示
处在第i行的皇后在ColumnIndex[i]列，例如ColumnIndex1=3表示
处在第1行的皇后在第3列上。接下来，分别用0~7这8个数字对ColumnIndex进行初始化。
注意，此时所有的皇后不同行也不同列。因此，我们只需要对ColumnIndex数组进行全排列，
判断每一个排列所对应的8个皇后的位置是否在对角线上，也就是对于数组下表i,j，
是不是 i-j==ColumnIndex[i]-ColumnIndex[j]，或者j-i=ColumnIndex[i]-ColumnIndex[j]。
*/
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
bool IsRight(int* ColumnIndex, int length) {
  bool result = true;
  for(int i = 0; i < length; i++)
    for(int j = i + 1; j < length; j++)
      if(i - j == ColumnIndex[i] - ColumnIndex[j] || i - j == ColumnIndex[j] - ColumnIndex[i]) {
        result = false;
        break;
      }
  return result;
}
void Permutation(int* ColumnIndex, int* pBegin) {
  if(*pBegin == -1) {
    bool result = IsRight(ColumnIndex, 8);
    if(result) {
      for(int i = 0; i < 8; i++)
        cout << ColumnIndex[i];
      cout << endl;
    }
  }
  for(int *i = pBegin; *i != -1; i++) {
    swap(pBegin, i);
    Permutation(ColumnIndex, pBegin+1);
    swap(pBegin, i);
  }
}
void EightQueens() {
  int ColumnIndex[9] = {0, 1, 2, 3, 4, 5, 6, 7, -1};
  Permutation(ColumnIndex, ColumnIndex);
}


int main() {
  EightQueens();

  return 0;
}
