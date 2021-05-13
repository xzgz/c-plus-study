#include "common_function.h"
#include <iostream>
#include <vector>
#include <unordered_set>

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

int main() {
    string s = "()())()";
    Solution so;
    vector<string> res = so.removeInvalidParentheses(s);
    for (string v : res) cout << v << endl;

    vector<int> nums = { 3, 4, -1, 1 };
    Print1DVector(nums);
    int fmp = FirstMissingPositive(nums);
    Print1DVector(nums);
    cout << "fmp: " << fmp << endl;

    return 0;
}
