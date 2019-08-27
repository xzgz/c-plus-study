#include <bits/stdc++.h>

using namespace std;

vector<int> GetNext(const string& t) {
  vector<int> next(t.size(), 0);
  next[0] = -1;
  int j = 0, k = -1;

  while (j < t.size()) {
    if (k == -1 || t[j] == t[k]) {
      ++j;
      ++k;
      if (t[j] == t[k]) next[j] = next[k];
      else next[j] = k;
    }
	else {
      k = next[k];
    }
  }

  return next;
}

int KMP(const string& s, const string& t) {
  int i = 0, j = 0;
  vector<int> next = GetNext(t);

  while (i < s.size() && j < t.size()) {
    if (j == -1 || s[i] == t[j]) { ++i, ++j; }
    else j = next[j];
  }

  if (j == t.size()) return i - j;
  else return -1;
}

static void get_next(const char* dest, int next[]) {
  /* 计算回溯值 */

  int j = 0;
  int k = -1;
  next[0] = -1;
  int dest_len = strlen(dest);

  while(j < dest_len) {
    if(k == -1 || dest[j] == dest[k]) {
      ++j;
      ++k;
      if(dest[j] != dest[k]) {
        next[j] = k;
      } else {
        next[j] = next[k];
      }
      next[j] = k;
    } else {
      k = next[k];
    }
  }
}

int kmp(const char *src, const char* dest) {
  assert(src && dest);

  int i = 0;
  int j = 0;
  const int src_len = strlen(src);
  const int dest_len = strlen(dest);
  int next[dest_len];

  get_next(dest, next);

  i = 0;
  while(i < src_len && j < dest_len) {
    if(j == -1 || src[i] == dest[j]) {
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  return j >= dest_len ? i - dest_len : -1;
}

int main() {
  string s = "asdffas";
//  string t = "dffa";
  string t = "abcaababc";
//  int loc = KMP(s, t);
  int loc = kmp(s.data(), t.data());
  cout << loc;

  return 0;
}
