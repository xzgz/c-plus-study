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
  TestFunPtr();
  vector<int> prices = { 2, 5, 1, 2, 0, 5 };
  int max_p = maxProfit(prices);
  cout << max_p << endl;

  map<float, int> m;
  m[2.1] = 3;
  m[4] = 8;
  m[3.8] = 10;
  m.insert(pair<float, int>(1.99, 12));
//  m[1] = 12;
  auto it = m.begin();
  for (; it != m.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }

  cout << "**********\n";
  int i = 0;
  int *p;
  if (p == NULL) cout << "YES\n";
  else cout << "NO\n";
  cout << p;

  return 0;
}
