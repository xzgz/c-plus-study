#include <bits/stdc++.h>

using namespace std;

bool IsCoordValid(const int px, const int py, const int bx, const int by) {
  if (0 <= px && px <= bx && 0 <= py && py <= by) return true;
  else return false;
}

bool IsTherePassageway(const vector<vector<char> >& mat, const int n, const int m, const pair<int, int>& start,
                       const pair<int, int>& end) {
  int end_sur_pt_cnt = 0;
//  if (*(mat + end.first * m + end.second) == '.') {
//    if (IsCoordValid(end.second, end.first-1, m, n) && *(mat + (end.first-1) * m + end.second) == '.') end_sur_pt_cnt +=1;
//    if (IsCoordValid(end.second, end.first+1, m, n) && *(mat + (end.first+1) * m + end.second) == '.') end_sur_pt_cnt +=1;
//    if (IsCoordValid(end.second-1, end.first, m, n) && *(mat + end.first * m + end.second-1) == '.') end_sur_pt_cnt +=1;
//    if (IsCoordValid(end.second+1, end.first, m, n) && *(mat + end.first * m + end.second+1) == '.') end_sur_pt_cnt +=1;
//  } else {
//    end_sur_pt_cnt = 2;
//  }
  if (mat[end.first][end.second] == '.') {
    if (IsCoordValid(end.second, end.first-1, m, n) && mat[end.first-1][end.second] == '.') end_sur_pt_cnt +=1;
    if (IsCoordValid(end.second, end.first+1, m, n) && mat[end.first+1][end.second] == '.') end_sur_pt_cnt +=1;
    if (IsCoordValid(end.second-1, end.first, m, n) && mat[end.first][end.second-1] == '.') end_sur_pt_cnt +=1;
    if (IsCoordValid(end.second+1, end.first, m, n) && mat[end.first][end.second+1] == '.') end_sur_pt_cnt +=1;
  } else {
    end_sur_pt_cnt = 2;
  }
  if (end_sur_pt_cnt < 2) return false;

  bool is_used[n][m] = {0};
  queue<pair<int, int> > roads;
  pair<int, int> front;
  if (IsCoordValid(start.second, start.first, m, n)) roads.push(start);
  while (!roads.empty()) {
    int node_count = roads.size();
    for (int i = 0; i < node_count; ++i) {
      front = roads.front();
      roads.pop();

      pair<int, int> point(front.first-1, front.second);
      if (point == end) return true;
      if (IsCoordValid(point.second, point.first, m, n) && !is_used[point.first][point.second]
          && mat[point.first][point.second] == '.') {
        roads.push(point);
        is_used[point.first][point.second] = true;
      }
      point = make_pair(front.first+1, front.second);
      if (point == end) return true;
      if (IsCoordValid(point.second, point.first, m, n) && !is_used[point.first][point.second]
          && mat[point.first][point.second] == '.') {
        roads.push(point);
        is_used[point.first][point.second] = true;
      }
      point = make_pair(front.first, front.second-1);
      if (point == end) return true;
      if (IsCoordValid(point.second, point.first, m, n) && !is_used[point.first][point.second]
          && mat[point.first][point.second] == '.') {
        roads.push(point);
        is_used[point.first][point.second] = true;
      }
      point = make_pair(front.first, front.second+1);
      if (point == end) return true;
      if (IsCoordValid(point.second, point.first, m, n) && !is_used[point.first][point.second]
          && mat[point.first][point.second] == '.') {
        roads.push(point);
        is_used[point.first][point.second] = true;
      }
    }
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
//    void *mat = calloc(n*m, sizeof(char));
    vector<vector<char> > mat(n, vector<char>(m, 0));
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        char c;
        cin >> c;
//        *((char *)mat + j * m + k) = c;
        mat[j][k] = c;
      }
    }
    int coord;
    cin >> coord;
    start.first = coord - 1;
    cin >> coord;
    start.second = coord - 1;
    cin >> coord;
    end.first = coord - 1;
    cin >> coord;
    end.second = coord - 1;

//    bool is_there_passageway = IsTherePassageway((char *)mat, n, m, start, end);
    bool is_there_passageway = IsTherePassageway(mat, n, m, start, end);
    if (is_there_passageway) result[i] = "YES";
    else result[i] = "NO";
//    free(mat);
  }
  for (int i = 0; i < t; ++i) {
    cout << result[i] << endl;
  }

  return 0;
}
