#include <bits/stdc++.h>

using namespace std;

/*
 * 有N个城市，各城市之间总共有M条路线，每条路线用时为ti，同时每个城市有Qi个蛋糕。
 * 现在有一个人从A城市出发前往B城市，问在用时最短的前提下，此人最多能获得多少蛋
 * 糕。假设A城市到B城市至少有一条路径。
 * 输入描述：第一行4个数，N，M，S，D，分别表示城市个数，路线总个数，出发城市编号，
 * 到达城市编号。第二行N个数，表示N个城市的蛋糕数量。接下来是M行个数，分别表示M
 * 条路线及其所需要的时间。
 *
 * 输入示例：
 * 4 5 1 4
 * 10 20 30 40
 * 1 2 2
 * 1 3 3
 * 2 3 2
 * 3 4 3
 * 2 4 4
 * 输出示例：
 * 6 80
 * 输出说明：
 * 行走路线为1->3->4
 */

struct Meta {
  int t;
  int q;
};

struct CityTime {
  int city;
  int time;
};

bool comp(Meta& a, Meta&b) {
  if (a.t < b.t) return true;
  else return false;
}

int main() {
  int N, M, S, D;
  cin >> N;
  cin >> M;
  cin >> S;
  cin >> D;
  vector<int> Q(N);
  for (int i = 0; i < N; ++i) {
    int qi;
    cin >> qi;
    Q[i] = qi;
  }
  unordered_map<int, vector<CityTime> > roads;
  for (int i = 0; i < M; ++i) {
    int ii, jj, ti;
    vector<CityTime> next_city_set;
    CityTime ct;
    cin >> ii;
    cin >> jj;
    cin >> ti;
    ct.city = jj - 1;
    ct.time = ti; if (roads.count(ii-1)) {
      next_city_set = roads[ii - 1];
      next_city_set.push_back(ct);
      roads[ii-1] = next_city_set;
    } else {
      next_city_set.push_back(ct);
      roads[ii-1] = next_city_set;
    }
  }

  queue<int> nodes;
  queue<int> rt;
  queue<int> sumq;
  vector<Meta> results;
  int front;
  int pre_t;
  int pre_q;
  nodes.push(S-1);
  rt.push(0);
  sumq.push(Q[S-1]);
  while (!nodes.empty()) {
    int node_count = nodes.size();
    for (int i = 0; i < node_count; ++i) {
      front = nodes.front();
      nodes.pop();
      pre_t = rt.front();
      rt.pop();
      pre_q = sumq.front();
      sumq.pop();
      for (int j = 0; j < N; ++j) {
        bool have_road = false;
        int use_time = 0;
        if (roads.count(front)) {
          vector<CityTime> next_city_set = roads[front];
          for (CityTime ct : next_city_set)
            if (ct.city == j) {
            have_road = true;
            use_time = ct.time;
            break;
          }
        }
        if (j != i && have_road) {
          if (j == D-1) {
            Meta temp;
            temp.t = pre_t + use_time;
            temp.q = pre_q + Q[j];
            results.push_back(temp);
            break;
          } else {
            nodes.push(j);
            rt.push(pre_t + use_time);
            sumq.push(pre_q + Q[j]);
          }
        }
      }
    }
  }

  sort(results.begin(), results.end(), comp);
  Meta first = results[0];
  Meta res;
  res.q = -1;
  for (Meta v : results) {
    if (v.t == first.t && v.q > res.q) {
      res.t = v.t;
      res.q = v.q;
    } else break;
  }
  cout << res.t << " " << res.q;

  return 0;
}
