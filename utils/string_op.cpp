#include <bits/stdc++.h>

using namespace std;

void String2IntArray(vector<int>& array, string& str) {
  int s, e;
  for (int i = 0; i < str.size(); ++i) {
	if ('0' <= str[i] && str[i] <= '9') {
	  s = i;
	  e = i;
	  for (int j = s; j < str.size(); ++j) {
		if (str[j] < '0' || str[j] > '9') {
		  e = j;
		  break;
		}
	  }
	  if (s != e) array.push_back(stoi(str.substr(s, e-s)));
	  i = e;
	}
  }
}

void String2IntArray2(vector<int>& array, string& str) {
  long order;
  while (!str.empty()) {
	string::iterator loc = find(str.begin(), str.end(), ' ');
	order = distance(str.begin(), loc);
	array.push_back(stoi(str.substr(0, order)));
	str.erase(0, 1+order);
  }
}
