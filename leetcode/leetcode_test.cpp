#include "common_function.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
private:
    int len_;
    string s_new_;
    unordered_set<string> valid_expressions_;

    void DFS(int index, int left_count, int right_count, int left_remove, int right_remove, string& path) {
        if (index == len_) {
            if (left_remove == 0 && right_remove == 0) valid_expressions_.insert(path);
            return;
        }

        char ch = s_new_[index];
        if (ch == '(' && left_remove > 0) {
            DFS(index + 1, left_count, right_count, left_remove - 1, right_remove, path);
        }
        if (ch == ')' && right_remove > 0) {
            DFS(index + 1, left_count, right_count, left_remove, right_remove - 1, path);
        }

        path.push_back(ch);
        if (ch != '(' && ch != ')') {
            DFS(index + 1, left_count, right_count, left_remove, right_remove, path);
        } else if (ch == '(') {
            DFS(index + 1, left_count + 1, right_count, left_remove, right_remove, path);
        } else if (left_count > right_count) {
            DFS(index + 1, left_count, right_count + 1, left_remove, right_remove, path);
        }
        path.pop_back();
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;

        len_ = s.length();
        s_new_ = s;
        int left_remove = 0;
        int right_remove = 0;
        for (int i = 0; i < len_; ++i) {
            if (s[i] == '(') {
                ++left_remove;
            } else if (s[i] == ')') {
                if (left_remove == 0) ++right_remove;
                if (left_remove > 0) --left_remove;
            }
        }

        string path;
        DFS(0, 0, 0, left_remove, right_remove, path);
        for (string s : valid_expressions_) res.push_back(s);
        return res;
    }
};

int FirstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[nums[i] - 1], nums[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

class UnionFind {
private:
    vector<int> parent_;
    vector<double> weight_;

public:
    UnionFind(int n) : parent_(vector<int>(n)), weight_(vector<double>(n)) {
        for (int i = 0; i < n; ++i) {
            parent_[i] = i;
            weight_[i] = 1.0;
        }
    }

    void Union(int x, int y, double value) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y) return;

        parent_[root_x] = root_y;
        weight_[root_x] = weight_[y] * value / weight_[x];
    }

    int find(int x) {
        if (x != parent_[x]) {
            int origin = parent_[x];
            parent_[x] = find(parent_[x]);
            weight_[x] *= weight_[origin];
        }
        return parent_[x];
    }

    double IsConnected(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y) return weight_[x] / weight_[y];
        else return -1.0;
    }
};

class CalcEquationSolution {
public:
    vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries) {
        int eq_size = equations.size();
        UnionFind uf = UnionFind(2 * eq_size);
        unordered_map<string, int> hash_map;
        int id = 0;
        for (int i = 0; i < eq_size; ++i) {
            vector<string> eq = equations[i];
            string var1 = eq[0];
            string var2 = eq[1];
            if (hash_map.find(var1) == hash_map.end()) {
                hash_map[var1] = id++;
            }
            if (hash_map.find(var2) == hash_map.end()) {
                hash_map[var2] = id++;
            }
            uf.Union(hash_map[var1], hash_map[var2], values[i]);
        }

        int query_size = queries.size();
        vector<double> res(query_size);
        for (int i = 0; i < query_size; ++i) {
            string var1 = queries[i][0];
            string var2 = queries[i][1];
            if (hash_map.find(var1) == hash_map.end() || hash_map.find(var2) == hash_map.end()) {
                res[i] = -1.0;
                continue;
            }
            int id1 = hash_map[var1];
            int id2 = hash_map[var2];
            res[i] = uf.IsConnected(id1, id2);
        }

        return res;
    }
};

class MinMeetingRoomsSolution1 {
public:
    int minMeetingRooms(vector<vector<int> > intervals) {
        if (intervals.empty()) return 0;

        int n = intervals.size();
        vector<int> start(n);
        vector<int> end(n);
        for (int i = 0; i < n; ++i) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int st_ptr = 0, end_ptr = 0;
        int used_rooms = 0;
        while (st_ptr < n) {
            if (start[st_ptr] >= end[end_ptr]) {
                --used_rooms;
                ++end_ptr;
            }
            ++used_rooms;
            ++st_ptr;
        }

        return used_rooms;
    }
};

auto CmpFun = [](int a, int b) {
    return a > b;
};

class MinMeetingRoomsSolution2 {
public:
    int minMeetingRooms(vector<vector<int> > intervals) {
        if (intervals.empty()) return 0;

//        priority_queue<int, vector<int>, greater<int>() > pq;  // error
        priority_queue<int, vector<int>, greater<int> > pq;
//        priority_queue<int, vector<int>, decltype(CmpFun)> pq(CmpFun);
//        sort(intervals.begin(), intervals.end());
        sort(intervals.begin(), intervals.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0];
        });

        pq.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }

        return pq.size();
    }
};

class FindUnsortedSubarraySolution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int lmin = numeric_limits<int>::max();
        int rmax = numeric_limits<int>::min();
        bool flag = false;
        int n = nums.size();

        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) flag = true;
            if (flag) lmin = std::min(lmin, nums[i]);
        }

        flag = false;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) flag = true;
            if (flag) rmax = std::max(rmax, nums[i]);
        }

        int l, r;
        for (l = 0; l < n; ++l) {
            if (nums[l] > lmin) break;
        }
        for (r = n - 1; r >= 0; --r) {
            if (nums[r] < rmax) break;
        }

        return r >= l ? r - l + 1 : 0;
    }
};

class LeastIntervalSolution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty()) return 0;
        int freq[26] = { 0 };
        for (char& ch : tasks) {
            freq[ch - 'A']++;
        }

        int max_exec = *std::max_element(freq, freq + 26, [](const int& u, const int& v) {
            return u < v;
        });
        int max_count = std::accumulate(freq, freq + 26, 0, [=](int acc, const int& u) {
            return acc + (u == max_exec);
        });

        return std::max((max_exec - 1) * (n + 1) + max_count, int(tasks.size()));
    }
};

void test1() {
    string s = "()())()";
    Solution so;
    vector<string> res1 = so.removeInvalidParentheses(s);
    for (string v : res1) cout << v << endl;

    vector<int> nums = { 3, 4, -1, 1 };
    Print1DVector(nums);
    int fmp = FirstMissingPositive(nums);
    Print1DVector(nums);
    cout << "fmp: " << fmp << endl;

    vector<vector<string> > equations = { { "a", "b" }, { "b", "c" } };
    vector<double> values = { 2.0, 3.0 };
    vector<vector<string> > queries = { { "a", "c" }, { "b", "a" }, { "a", "e" }, { "a", "a" }, { "x", "x" } };
    CalcEquationSolution cso;
    vector<double> res2 = cso.calcEquation(equations, values, queries);
    Print1DVector(res2);

    unordered_map<string, int> um;
    um["a"] = 1;
    um["b"] = 2;
    um["a"] = 3;
    cout << um["a"] << endl;
    if (um.find("a") != um.end()) {
        cout << "um.find(\"a\") != um.end()" << endl;
    }
    cout << "um.count(\"a\") = " << um.count("a") << endl;

    if (um.find("a1") == um.end()) {
        cout << "um.find(\"a1\") == um.end()" << endl;
    }
    cout << "um[\"a1\"] = " << um["a1"] << endl;
    if (um.find("a1") != um.end()) {
        cout << "um.find(\"a1\") != um.end()" << endl;
    }
    um["a1"] = 8;
    cout << "um[\"a1\"] = " << um["a1"] << endl;
}

void test2() {
    vector<vector<int> > intervals = { { 0, 30 }, { 5, 10 }, { 15, 20 } };
    MinMeetingRoomsSolution1 mso1;
    MinMeetingRoomsSolution2 mso2;
    int used_rooms;
    used_rooms = mso1.minMeetingRooms(intervals);
    cout << "used_rooms: " << used_rooms << endl;
    used_rooms = mso2.minMeetingRooms(intervals);
    cout << "used_rooms: " << used_rooms << endl;

    vector<int> nums = { 2,6,4,8,10,9,15 };
    FindUnsortedSubarraySolution fuso;
    int len = fuso.findUnsortedSubarray(nums);
    cout << "len: " << len << endl;

    vector<char> tasks = { 'A', 'A', 'A', 'B', 'B', 'B' };
    int n = 2;
    LeastIntervalSolution liso;
    int least_time = liso.leastInterval(tasks, n);
    cout << "least_time: " << least_time << endl;
}

int main() {
//    test1();
    test2();

    return 0;
}
