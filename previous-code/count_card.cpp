#include<vector>
#include<iostream>

using namespace std;

const int M = 10007;
const int MAXN = 2000;
int C[MAXN+1][MAXN+1];

void Initial()
{
  int i,j;
  for(i=0; i<=MAXN; ++i)
  {
    C[0][i] = 0;
    C[i][0] = 1;
  }
  for(i=1; i<=MAXN; ++i)
  {
    for(j=1; j<=MAXN; ++j)
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % M;
  }
}

int Combination(int n, int m)
{
  return C[n][m];
}


int main()
{
  int n, s, k;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; ++i)
  {
    cin >> k;
  }

  Initial();
  int count = Combination(n, s) * 2;
  int max_count = 1e9 + 7;
  cout << count % max_count;
  return 0;
}
