#include <bits/stdc++.h>

using namespace std;

/*
leetcode 416:
Given a non-empty array containing only positive integers, find if the array can be partitioned into
two subsets such that the sum of elements in both subsets is equal.
Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.

Example 1:
Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/

/*
思路：可以看作背包问题。背包的总容量为数组中所有数总和的一半，从数组中选数，将背包恰好装满。
detail: https://juejin.im/post/5b40c99ee51d45190b615f33#heading-0
*/

// 递归方法
class Solution1 {
 private:
  // memo[i][c] 表示使用索引为[0...i]的这些元素,是否可以完全填充一个容量为c的背包
  // -1 表示为未计算; 0 表示不可以填充; 1 表示可以填充
  vector<vector<int>> memo;

  // 使用nums[0...index], 是否可以完全填充一个容量为sum的背包
  bool tryPartition(const vector<int> &nums, int index, int sum){
    if( sum == 0 ) {
      return true;
    }
    if( sum < 0 || index < 0 ) {
      return false;

    }

    if( memo[index][sum] != -1 ) {
      return memo[index][sum] == 1;
    }

    memo[index][sum] = (tryPartition(nums, index-1 , sum ) ||
                        tryPartition(nums, index-1 , sum - nums[index] ) ) ? 1 : 0;

    return memo[index][sum] == 1;
  }
 public:
  bool canPartition(vector<int>& nums) {

    int sum = 0;
    for( int i = 0 ; i < nums.size() ; i ++ ){
      assert( nums[i] > 0 );
      sum += nums[i];
    }
    if( sum%2 ) {
      return false;
    }

    memo = vector<vector<int>>(nums.size(), vector<int>(sum/2+1,-1));
    return tryPartition(nums, nums.size()-1 , sum/2 );
  }
};

// 动态规划方法
class Solution2 {

 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for( int i = 0 ; i < nums.size() ; i ++ ){
      assert( nums[i] > 0 );
      sum += nums[i];
    }
    if( sum%2 ) {
      return false;
    }

    int n = nums.size();
    int C = sum / 2;
    vector<bool> memo(C+1, false);

    for ( int i = 0; i <= C; i++ ) {
      memo[i] = ( nums[0] == i );
    }

    for ( int i = 1; i < n; i++ ) {
      for ( int j = C; j >= nums[i]; j-- ) {
        memo[j] = memo[j] || memo[ j - nums[i] ];
      }
    }

    return memo[C];
  }
};


int main() {
  vector<int> nums1 = { 1, 5, 11, 5 };
  vector<int> nums2 = { 1, 2, 3, 5 };
//  Solution1 so;
  Solution2 so;

  bool can_be_partitioned = false;
  can_be_partitioned = so.canPartition(nums1);
  if (can_be_partitioned) cout << "nums1 can be partioned\n";
  else cout << "nums1 can not be partioned\n";
  can_be_partitioned = false;
  can_be_partitioned = so.canPartition(nums2);
  if (can_be_partitioned) cout << "nums2 can be partioned\n";
  else cout << "nums2 can not be partioned\n";
}
