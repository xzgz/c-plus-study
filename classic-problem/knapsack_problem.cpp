#include <bits/stdc++.h>

using namespace std;

/*
detail: https://juejin.im/post/5b40c99ee51d45190b615f33#heading-0
背包问题：有一个背包，它的容量为C(Capacity)。现在有n中不同的物品，编号为0…n-1，
其中每一件物品的重量为w(i)，价值为v(i)。问可以向这个背包中盛放哪些物品，
使得在不超过背包容量的基础上，物品的总价值最大。
*/

/*
思路：F(n,C)表示在考虑将前n个物品放进容量为C的背包，能取得的最大价值。
对于F(i,c)，有两种情况，将第i个物品加入和直接忽略第i个物品
F(i,C) = max{F(i-1, C), v(i) + F(i-1, C-w(i))}
*/

class Solution1 {
 private:
  vector<vector<int> > memo;
  int bestValue(const vector<int>& w, const vector<int>& v, int index, int c) {
    if (c <= 0 || index < 0) return 0;
    if (memo[index][c] != -1) return memo[index][c];

    int res = bestValue(w, v, index-1, c);
    if (c >= w[index]) res = max(res, v[index]+bestValue(w, v, index-1, c-w[index]));
    memo[index][c] = res;

    return res;
  }

 public:
  int knapsack01(const vector<int>& w, const vector<int>& v, int c) {
    assert(w.size() == v.size() && c >= 0);
    int n = w.size();
    if (n == 0 || c == 0) return 0;

    memo = vector<vector<int> >(n, vector<int>(c+1, -1));
    return bestValue(w, v, n-1, c);
  }
};

class Solution2 {
 public:
  int knapsack01(const vector<int>& w, const vector<int>& v, int c) {
    assert(w.size() == v.size() && c >= 0);
    int n = w.size();
    if (n == 0 || c == 0) return 0;

    vector<vector<int> > memo(n, vector<int>(c+1, 0));
    for (int j = 0; j <= c; ++j) memo[0][j] = (j >= w[0] ? v[0] : 0);
    for (int i = 1; i < n; ++i)
      for (int j = 0; j <= c; ++j) {
      memo[i][j] = memo[i-1][j];
      if (j >= w[i]) memo[i][j] = max(memo[i][j], v[i]+memo[i-1][j-w[i]]);
    }

    return memo[n-1][c];
  }
};

class Solution3 {
 public:
  int knapsack01(const vector<int>& w, const vector<int>& v, int c) {
	assert(w.size() == v.size());
	int n = w.size();
	if (n == 0 || c == 0) return 0;

	vector<vector<int> > memo(2, vector<int>(c + 1, 0));
	for (int j = 0; j <= c; ++j) memo[0][j] = (j >= w[0] ? v[0] : 0);
	for (int i = 1; i < n; ++i)
	  for (int j = 0; j <= c; ++j) {
		memo[i % 2][j] = memo[(i - 1) % 2][j];
		if (j >= w[i]) memo[i % 2][j] = max(memo[i % 2][j], v[i] + memo[(i - 1) % 2][j - w[i]]);
	  }

	return memo[(n - 1) % 2][c];
  }
};

class Solution4 {
 public:
  int knapsack01(const vector<int>& w, const vector<int>& v, int c) {
	assert(w.size() == v.size() && c >= 0);
	int n = w.size();
	if (n == 0) return 0;

	vector<int> memo(c + 1, 0);
	for (int j = 0; j <= c; ++j) memo[j] = (j >= w[0] ? v[0] : 0);
	for (int i = 1; i < n; ++i)
	  for (int j = c; j >= w[i]; --j)
		memo[j] = max(memo[j], v[i] + memo[j - w[i]]);

	return memo[c];
  }
};

int main() {
  vector<int> w = { 2, 3, 4, 5 };
  vector<int> v = { 3, 4, 5, 6 };
  int c = 8;
  Solution1 so;
//  Solution2 so;
//  Solution3 so;
//  Solution4 so;

  int max_value = so.knapsack01(w, v, c);
  cout << "max value: " << max_value << endl;
}
