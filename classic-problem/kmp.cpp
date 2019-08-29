#include <bits/stdc++.h>

using namespace std;

static vector<int> GetNext(const string& t) {
  vector<int> next(t.size(), 0);
  int t_len = t.size();
  next[0] = -1;
  int j = 0, k = -1;

  while (j < t_len) {
    if (k == -1 || t[j] == t[k]) {
      ++j;
      ++k;
      // t[j]==t[k] means t(0)t(1)...t(k)==t(j-k)t(j-k+1)...t(j)
      if (t[j] == t[k]) next[j] = next[k];
      else next[j] = k;
    } else k = next[k];
  }

  return next;
}

int KMP(const string& s, const string& t) {
  int i = 0, j = 0;
  int s_len = s.size();
  int t_len = t.size();
  vector<int> next = GetNext(t);

  while (i < s_len && j < t_len) {
    if (j == -1 || s[i] == t[j]) ++i, ++j;
    else j = next[j];
  }

  if (j == t_len) return i - j;
  else return -1;
}

int main() {
  string s = "abcdabcabcda";
  string t = "abcabcd";
  int loc = KMP(s, t);
  cout << loc;

  return 0;
}
