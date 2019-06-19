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

// 递归方法
class Solution1 {
 private:
  vector<vector<int>> memo;
  // 用 [0...index]的物品,填充容积为c的背包的最大价值
  int bestValue(const vector<int> &w, const vector<int> v, int index, int c){

    if( c <= 0 || index < 0 ) {
      return 0;
    }

    if( memo[index][c] != -1 ) {
      return memo[index][c];
    }

    int res = bestValue(w, v, index-1, c);
    if( c >= w[index] ) {
      res = max( res , v[index] + bestValue(w, v, index-1, c-w[index]));
    }

    memo[index][c] = res;
    return res;
  }
 public:
  int knapsack01(const vector<int> &w, const vector<int> &v, int C){

    assert( w.size() == v.size() && C >= 0 );
    int n = w.size();
    if( n == 0 || C == 0 )
      return 0;

    memo = vector<vector<int>>( n, vector<int>(C+1,-1));
    return bestValue(w, v, n-1, C);
  }
};

// 动态规划方法
// 时间复杂度：O(nC),空间复杂度：O(nC)。
class Solution2 {
 public:
  // 用 [0...index]的物品,填充容积为c的背包的最大价值
  int knapsack01(const vector<int> &w, const vector<int> &v, int C){
    assert( w.size() == v.size() && C >= 0 );
    int n = w.size();
    if ( n == 0) {
      return 0;
    }

    vector<vector<int>> memo( n, vector<int>(C+1,0));

    for ( int j = 0; j <= C; j++ ) {
      memo[0][j] = ( j >= w[0] ? v[0] : 0 );
    }

    for ( int i = 1; i < n; i++ ) {
      for ( int j = 0; j <= C; j++ ) {
        // 0~i这些物品容积为j的背包获得的最大值
        memo[i][j] = memo[i-1][j];
        if( j >= w[i] ) {
          memo[i][j] = max( memo[i][j], v[i] + memo[i-1][j-w[i]]);
        }
      }
    }

    return memo[n-1][C];
  }
};

/*
优化空间复杂度：
我们分析一下状态转移方程：F(i,C) = max{F(i-1, C), v(i) + F(i-1, C-w(i))}
第i行元素只依赖于第i-1行元素。理论上，只需要保持两行元素。空间复杂度：O(2*C)=O(C)。
*/
class Solution3 {
 public:
  int knapsack01(const vector<int> &w, const vector<int> &v, int C) {
    assert( w.size() == v.size() && C >= 0 );
    int n = w.size();
    if( n == 0 && C == 0 )
      return 0;

    vector<vector<int>> memo( 2, vector<int>(C+1,0));

    for( int j = 0 ; j <= C ; j ++ )
      memo[0][j] = ( j >= w[0] ? v[0] : 0 );

    for( int i = 1 ; i < n ; i ++ )
      for( int j = 0 ; j <= C ; j ++ ){
        memo[i%2][j] = memo[(i-1)%2][j];
        if( j >= w[i] )
          memo[i%2][j] = max( memo[i%2][j], v[i] + memo[(i-1)%2][j-w[i]]);
      }
    return memo[(n-1)%2][C];
  }
};

/*
继续优化空间复杂度：
可以从最大的背包容量开始，求解背包容量渐渐递减时所能装的物品的最大价值，
这样空间复杂度就减少为：O(C)。
*/
class Solution4 {
 public:
  int knapsack01(const vector<int> &w, const vector<int> &v, int C){
    assert( w.size() == v.size() && C >= 0 );
    int n = w.size();
    if( n == 0 || C == 0 )
      return 0;

    vector<int> memo(C+1,0);

    for( int j = 0 ; j <= C ; j ++ )
      memo[j] = ( j >= w[0] ? v[0] : 0 );

    for( int i = 1 ; i < n ; i ++ )
      for( int j = C ; j >= w[i] ; j -- )
        memo[j] = max( memo[j], v[i] + memo[j-w[i]]);

    return memo[C];
  }
};


int main() {
  vector<int> w = { 2, 3, 4, 5 };
  vector<int> v = { 3, 4, 5, 6 };
  int C = 8;
//  Solution1 so;
//  Solution2 so;
//  Solution3 so;
  Solution4 so;

  int max_value = so.knapsack01(w, v, C);
  cout << "max value: " << max_value << endl;
}


