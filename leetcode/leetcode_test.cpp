#include "common_function.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <map>

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

class MinMeetingRoomsSolution2 {
public:
    int minMeetingRooms(vector<vector<int> > intervals) {
        if (intervals.empty()) return 0;

        priority_queue<int, vector<int>, greater<int> > pq;
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

class WordBreakSolution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set<string>();
        int max_word_len = 0;
//        unsigned int max_word_len = 0;
        for (auto word: wordDict) {
            wordDictSet.insert(word);
            max_word_len = std::max(int(max_word_len), int(word.size()));
        }

        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0 && j >= i - max_word_len; --j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

class IsPalindromeSolution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};

class MaxPointsSolution {
public:
    //求最大公约数
    int gcd(int a, int b) {
        int g;
        while(b != 0) {
            g = a%b;
            a = b;
            b = g;
        }
        return a;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), max_count = 2;
        if (n <= 2) return n;

        map<pair<int, int>, int> m;     //最简斜率，<dx, dy>计数
        int i, j, dx, dy, g;
        for (i = 0; i < n - max_count; ++i) {
            m.clear();
            int count = 0;
            int horisontal_lines = 0;
            int duplicates = 0;
            int sign;
            for (j = i + 1; j < n; ++j) {
                dx = points[i][0] - points[j][0];
                dy = points[i][1] - points[j][1];
                if (dx == 0 && dy == 0) {
                    ++duplicates;
                } else if (dy == 0) {
                    ++horisontal_lines;
                } else {
                    sign = dx == 0 ? 0 : dx / abs(dx) * dy / abs(dy);
                    dx = abs(dx);
                    dy = abs(dy);
                    g = gcd(dx, dy);                        //求最大公约数，参数取正数
                    m[{sign * dx / g, dy / g}]++;    //经过i点，斜率一样的点，计数+1
                }
            }
            //遍历经过i点的所有直线
            for (auto p : m) {
                //经过i点的所有直线中某个斜率的最多
                count = std::max(count, p.second);
            }
            count = std::max(count, horisontal_lines);
            count = count + duplicates + 1;
            max_count = std::max(max_count, count);
        }
        return max_count;
    }
};

struct TrieNode {
    vector<TrieNode*> children;
    string* word;
    TrieNode() : word(nullptr), children(26) {};
    ~TrieNode() {
        for (const auto& child : children)
            delete child;
    }
};

class FindWordsSolution {
public:
    int m, n;
    vector<vector<int> > dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    vector<string> ans;

    void walk(vector<vector<char> >& board, int x, int y, TrieNode *parent) {
        const char c = board[x][y];
        TrieNode *curr = parent->children[c - 97];
        if (!curr) return;
        if (curr->word) {
            ans.emplace_back(*curr->word);
            curr->word = nullptr;
        }
        //   if (curr->children.empty()) {
        //       delete curr;
        //       curr = nullptr;
        //       parent->children[c - 97] = nullptr;
        //       return;
        //   }

        board[x][y] = '#';
        for (auto d : dir) {
            int i = x + d[0], j = y + d[1];
            if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] != '#') {
                if (curr->children[board[i][j] - 97]) {
                    walk(board, i, j, curr);
                }
            }
        }
        board[x][y] = c;
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        TrieNode root;
        for (auto& word : words) {
            TrieNode* p = &root;
            for (const auto& c : word) {
                if (!p->children[c - 97])
                    p->children[c - 97] = new TrieNode();
                p = p->children[c - 97];
            }
            p->word = &word;
        }

        m = board.size(), n = board[0].size();
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (root.children[board[x][y] - 97]) {
                    walk(board, x, y, &root);
                }
            }
        }

        return ans;
    }
};

class CountSmallerSolution {
private:
    vector<int> c;
    vector<int> a;

    void Init(int length) {
        c.resize(length, 0);
    }

    int LowBit(int x) {
        return x & (-x);
    }

    void Update(int pos) {
        while (pos < c.size()) {
            c[pos] += 1;
            pos += LowBit(pos);
        }
    }

    int Query(int pos) {
        int ret = 0;

        while (pos > 0) {
            ret += c[pos];
            pos -= LowBit(pos);
        }

        return ret;
    }

    void Discretization(vector<int>& nums) {
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }

    int getId(int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> resultList;

        Discretization(nums);

        Init(nums.size());

        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            int id = getId(nums[i]);
            Update(id);
            resultList.push_back(Query(id - 1));
        }

        reverse(resultList.begin(), resultList.end());

        return resultList;
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

    WordBreakSolution wbso;
    string s = "bb";
//    string s = "leetcode";
    vector<string> word_dict = { "a", "b", "bbb", "bbbb" };
//    vector<string> word_dict = { "leet", "code" };
    bool s_can_break;
    s_can_break = wbso.wordBreak(s, word_dict);
    cout << "s_can_break: " << s_can_break << endl;

    unordered_map<char, string> ismap;
    ismap['1'] = "asd";
    char k = '1';
    unordered_map<char, string>& map2 = ismap;
    // error, no viable overloaded operator[] for type 'const unordered_map<char, std::string>'
//    const unordered_map<char, string>& map2 = ismap;
    const string& str = map2[k];
    cout << str << endl;

    int a, b;
    b = -3;
    a = b >> 1;
    cout << "a: " << a << endl;
    b = 3;
    a = b >> 1;
    cout << "a: " << a << endl;
}

void TestIsPalindromeSolution() {
    IsPalindromeSolution ipso;
    string s = "A man, a plan, a canal: Panama";
    bool is_palindrome;
    is_palindrome = ipso.isPalindrome(s);
    cout << boolalpha << "is_palindrome = " << is_palindrome << endl;
}

void TestMaxPointsSolution() {
    vector<vector<int> > points = { { 0, 0 }, { 2, 2 }, { -1, -1 } };
    MaxPointsSolution mpso;
    int max_num_point_on_one_line = mpso.maxPoints(points);
    cout << "max_num_point_on_one_line = " << max_num_point_on_one_line << endl;
}

void TestCountSmallerSolution() {
    vector<int> nums = { 3, 9, 5, 2, 6, 1, 3 };
    CountSmallerSolution csso;
    vector<int> res = csso.countSmaller(nums);
    for (int val : res) cout << val << " ";
    cout << endl;
}

void TestFindWordsSolution() {
//    vector<vector<char> > board = { { 'a', 'a' } };
//    vector<string> words = { "aa" };
    vector<vector<char> > board = {
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
            { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' },
    };
    vector<string> words = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
    FindWordsSolution fwso;
    vector<string> res = fwso.findWords(board, words);
    for (string str : res) {
        cout << str << endl;
    }
}

int main() {
//    test1();
//    test2();
//    TestIsPalindromeSolution();
//    TestMaxPointsSolution();
//    TestFindWordsSolution();
    TestCountSmallerSolution();

    return 0;
}
