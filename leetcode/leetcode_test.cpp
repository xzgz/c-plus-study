#include "common_function.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

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

int main() {
    string s = "()())()";
    Solution so;
    vector<string> res1 = so.removeInvalidParentheses(s);
    for (string v : res1) cout << v << endl;

    vector<int> nums = { 3, 4, -1, 1 };
    Print1DVector(nums);
    int fmp = FirstMissingPositive(nums);
    Print1DVector(nums);
    cout << "fmp: " << fmp << endl;

    vector<vector<string> > equations = { { "a", "b" }, { "b"," c" } };
    vector<double> values = { 2.0, 3.0 };
    vector<vector<string> > queries = { { "a", "c" }, { "b", "a" }, { "a", "e" }, { "a", "a" }, { "x", "x" } };
    CalcEquationSolution cso;
    vector<double> res2 = cso.calcEquation(equations, values, queries);
    Print1DVector(res2);

    return 0;
}
