#include <bits/stdc++.h>

using namespace std;

/*
题目：字符的所有组合
输入三个字符a、b、c，组合有：a, b, c , ab, ac, bc, abc。
*/

/*
思路1：假设输入n个字符，则这n个字符能构成长度为1的组合、长度为2的组合、……、长度为n的组合。
在求n个字符组成长度为m的组合的时候，与字符串全排列的求解思想类似，我们可以把这n个字符分为两个部分：
第一个字符和剩余的其他所有的n-1个字符。这个时候可以分为两种情况：
如果组合里包含第一个字符，则从所有剩余n-1个字符里选取m-1个字符；
如果组合里不包含第一个字符，则下一步在剩余的n-1个字符选取m个字符。
*/
void CombinationCore(char *str, int number, vector<char>& result) {
  if(number == 0)
  {
    vector<char>::iterator iter = result.begin();
    for(; iter != result.end(); ++iter)
      cout << *iter;
    cout << endl;
    return;
  }
  if(*str == '\0')
    return;
  // n-1个字符串中，选取number-1个字符
  result.push_back(*str);
  CombinationCore(str+1, number-1, result);
  // n-1个字符串中，选取number个字符
  result.pop_back();
  CombinationCore(str+1, number, result);
}
void Combination(char* str)
{
  if(str == NULL)
    return;
  int length = strlen(str);
  vector<char> result;
  for(int i = 1; i <= length; i++)
    CombinationCore(str, i, result);
}

/*
思路2：假设一共有n个字符，则可能的组合结果共有2^n-1种。以输入3个字符a、b、c为例：
3个字符，可以用3个位来表示，从右到左的每一位分别用来代表a、b、c，
该位为1表示取该元素，该位为0表示不取该元素。例如如组合a表示为001，组合b表示为010，
组合ac表示为101，组合abc表示为111，而000是没有意义的，所以总共的结果就是2^n-1种。
因此，我们可以从值1开始循环到2^n-1，输出每个值所代表的组合即可。
*/
void Combination2(char *str) {
  if(str == NULL)
    return;
  int i,j,temp;
  int length = strlen(str);
  int n = 1 << length;       // n为2^n-1(111)
  for(i = 1; i < n; i++) {   // 依次输出值1到2^n-1所代表值的组合
    for(j = 0; j < length; j++) {  // 判断第j位是否为1
      temp = i;
      if(temp & (1<<j))
        cout << *(str+j);
    }
    cout << endl;
  }
}


bool IsContainChar(char *p_begin, char c) {
  char *p = p_begin;
  while ('\0' != *p) {
    if (c == *p) return true;
    p++;
  }
  return false;
}
void RemoveDuplicateChar(char *str) {
  if (*str == '\0') return;

  vector<char> result;
  char *p = str;
  while ('\0' != *p) {
    char c = *p;
    bool contain_c = IsContainChar(p + 1, c);
    if (!contain_c) result.push_back(c);
    p++;
  }
  char *pr = str;
  for (vector<char>::iterator it = result.begin(); it != result.end(); ++it) {
    *pr = *it;
    pr++;
  }
  *pr = '\0';
}


int main() {
  char str[] = "aab";

//  RemoveDuplicateChar(str);
//  cout << str << endl;

  Combination(str);
  cout << "******************\n";
  Combination2(str);

  return 0;
}

