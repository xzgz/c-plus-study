#include<vector>
#include<iostream>


using namespace std;


int count_coin(int n, int m)
{
  int coin_count = 0;

  while (m > 0)
  {
    if (m <= n)
    {
      coin_count += 1;
      return coin_count;
    }
    else
    {
      coin_count += m / n;
      m = m % n;

      if (m == 0) return coin_count;
    }
  }

  return 0;
}


int main()
{
  int n, m;
  cin >> n;
  cin >> m;
  cout << count_coin(n, m);

  return 0;
}

