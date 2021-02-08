//#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

/*
1. 两数之和
难度：简单
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。你可以假设每种输入
只会对应一个答案。但是，数组中同一个元素不能使用两遍。你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]

提示：
2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案

 */
bool Find(int target, const vector<vector<int> >& array) {
    int rows = array.size();
    int cols = rows ? array[0].size() : 0;
    int r = 0, c = cols - 1;
    while (r <= rows - 1 && c >= 0) {
        if (target == array[r][c]) return true;
        else if (target > array[r][c]) ++r;
        else --c;
    }

    return false;
}

int main() {
    vector<vector<int> > array = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
    int target = 7;
    bool flag = Find(target, array);
    cout << flag << endl;

    return 0;
}
