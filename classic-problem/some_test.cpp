#include <bits/stdc++.h>

using namespace std;

typedef void (*Ptf)();

void print() {
  cout << "print\n";
}

int maxProfit(vector<int>& prices) {
  if(prices.empty()) return 0;
  int n=prices.size();
  vector<int> f(n);
  vector<int> b(n);
  int min_price=prices[0];
  for(int i=1;i<n;i++){
    f[i]=max(f[i-1],prices[i]-min_price);
    min_price=min(prices[i],min_price);
  }
  int max_price=prices[n-1];
  for(int i=n-2;i>=0;i--){
    b[i]=max(b[i+1],max_price-prices[i]);
    max_price=max(max_price,prices[i]);
  }
  int res=0;
  for(int i=0;i<n-1;i++){
    res=max(res,max(f[i]+b[i+1],f[i]));
  }
  res=max(res,f[n-1]);
  return res;
}

void TestFunPtr() {
  Ptf fun1 = &print;
  Ptf fun2 = print;
  fun1();
  fun2();
}

int main() {
  string str;
  getline(cin, str);

  vector<int> array;
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

  string aa = str.substr(1, 0);
  cout << str;
//  cout << str.substr(1, 0);
  stoi(str.substr(1, 0));

  return 0;
}
