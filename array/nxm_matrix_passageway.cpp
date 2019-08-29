#include <bits/stdc++.h>

using namespace std;

bool IsCoordValid(const int px, const int py, const int bx, const int by) {
  if (0 <= px && px < bx && 0 <= py && py < by) return true;
  else return false;
}

bool IsRoad(const int px, const int py, const vector<vector<char> >& mat,
			const vector<vector<bool> >& is_used) {
  int by = mat.size();
  int bx = by ? mat[0].size() : 0;
  if (0 <= px && px < bx && 0 <= py && py < by
	  && mat[py][px] == '.' && !is_used[py][px]) return true;
  else return false;
}

bool IsTherePassagewayBFS(const vector<vector<char> >& mat, const int n, const int m,
						  const pair<int, int>& start, const pair<int, int>& end) {
  int end_sur_pt_cnt = 0;
  int dx[4] = { 0, 0, -1, 1 };
  int dy[4] = { -1, 1, 0, 0 };
  if (!(IsCoordValid(end.second, end.first, m, n) &&
		IsCoordValid(start.second, start.first, m, n))) return false;
  if (mat[end.first][end.second] == '.') {
	for (int i = 0; i < 4; ++i) {
	  if (IsCoordValid(end.second+dx[i], end.first+dy[i], m, n)
		  && mat[end.first+dy[i]][end.second+dx[i]] == '.') end_sur_pt_cnt += 1;
	}
  } else end_sur_pt_cnt = 2;
  if (end_sur_pt_cnt < 2) return false;
  if (start == end) return true;

  bool is_used[n][m] = { false };
  queue<pair<int, int> > roads;
  roads.push(start);
  pair<int, int> front;
  pair<int, int> point;
  while (!roads.empty()) {
    int node_count = roads.size();
    for (int i = 0; i < node_count; ++i) {
      front = roads.front();
      roads.pop();
      for (int j = 0; j < 4; ++j) {
		point = make_pair(front.first + dy[j], front.second + dx[j]);
		if (IsCoordValid(point.second, point.first, m, n) &&
			!is_used[point.first][point.second] && mat[point.first][point.second] == '.') {
		  if (point == end) return true;
		  roads.push(point);
		  is_used[point.first][point.second] = true;
		}
	  }
    }
  }

  return false;
}

bool IsTherePassagewayDFS(vector<vector<char> >& mat, const int n, const int m,
						  const pair<int, int>& start, const pair<int, int>& end) {
  int end_sur_pt_cnt = 0;
  int dx[4] = { 0, 0, -1, 1 };
  int dy[4] = { -1, 1, 0, 0 };
  if (!(IsCoordValid(end.second, end.first, m, n) &&
		IsCoordValid(start.second, start.first, m, n))) return false;
  if (mat[end.first][end.second] == '.') {
    for (int i = 0; i < 4; ++i) {
      if (IsCoordValid(end.second+dx[i], end.first+dy[i], m, n)
		  && mat[end.first+dy[i]][end.second+dx[i]] == '.') end_sur_pt_cnt +=1;
	}
  } else end_sur_pt_cnt = 2;
  if (end_sur_pt_cnt < 2) return false;
  if (start == end) return true;

  vector<vector<bool> > is_used(n, vector<bool>(m, false));
  stack<pair<int, int> > roads;
  mat[start.first][start.second] = '.';
  pair<int, int> cur = start;
  pair<int, int> top;
  int j = 0;
  while (IsRoad(cur.second, cur.first, mat, is_used) || !roads.empty()) {
	while (IsRoad(cur.second, cur.first, mat, is_used)) {
	  if (cur == end) return true;
	  roads.push(cur);
	  is_used[cur.first][cur.second] = true;
	  cur = make_pair(cur.first+dy[j], cur.second+dx[j]);
	}
	if (j == 0) top = roads.top();
	++j;
	cur = make_pair(top.first+dy[j], top.second+dx[j]);
	if (j == 3) { j = 0; roads.pop(); }
  }

  return false;
}

int main() {
  int t, n, m;
  pair<int, int> start, end;
  cin >> t;
  vector<string> result(t);
  for (int i = 0; i < t; ++i) {
    cin >> n;
    cin >> m;
    vector<vector<char> > mat(n, vector<char>(m, 0));
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        char c;
        cin >> c;
        mat[j][k] = c;
      }
    }
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    start.first = y1 - 1;
    start.second = x1 - 1;
    end.first = y2 - 1;
    end.second = x2 - 1;

//	bool is_there_passageway = IsTherePassagewayBFS(mat, n, m, start, end);
	bool is_there_passageway = IsTherePassagewayDFS(mat, n, m, start, end);
    if (is_there_passageway) result[i] = "YES";
    else result[i] = "NO";
  }
  for (int i = 0; i < t; ++i) {
    cout << result[i] << endl;
  }

  return 0;
}