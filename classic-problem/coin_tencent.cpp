#include <bits/stdc++.h>

using namespace std;

/*
refer to: https://www.nowcoder.com/discuss/241618?type=post&order=time&pos=&page=1
题目描述：
投掷n枚硬币，已知至少有p枚正面，q枚反面，请问这n枚硬币正面向上硬币数量的期望是多少
输入描述：
输入一行n,p,q（n为硬币枚数，p为至少正面次数，q为至少反面次数）
输出期望：输出取膜
示例输入：
2 1 0
示例输出：
333333337
说明：
期望为1/3x1+1/3x1+1/3x2=4/3，又因为333333337x3%1000000007=4，所以答案是333333337。
取模思路：把分子a加上1e9+7的整数倍直到能被分母b整除为止，然后返回整除时的商
 */
long Cnk(int n, int k) {
  if (n < k) return 0;
  if (k == 0) return 1;
  long num = Cnk(n-1, k-1) + Cnk(n-1, k);
  return num;
}

int getOne(int num) {
  int ret = 0;
  int tmp;
  while (num) {
	ret++;
	tmp = num - 1;
	num = num & tmp;
  }
  return ret;
}

long long fast_mod(long long a, long long b){
  int M = 1000000007;
  int step = 0;
  while((step * M + a) % b != 0)
	step += 1;
  return (step * M + a) / b;
}

int main() {
  int n, p, q;
  cin >> n >> p >> q;
  long long sum = 0;
  int pp = n - q;  // 正面的上界
  int count = 0;

  // 每个组合都是等概率的
  // 2^n种组合数，i每种取值就代表1种组合；0代表全为反面；2^n-1代表全为正面
  for (int i = 0; i < pow(2, n); i++) {
	int ones = getOne(i);  // 模拟正面的个数
	if (ones >= p && ones <= pp) {
	  count++;      // 合法组合数
	  sum += ones;  // 正面向上的个数
	}
  }

  cout << fast_mod(sum, count);
}
