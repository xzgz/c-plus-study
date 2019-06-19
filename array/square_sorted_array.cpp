//Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.
//
//
//
//Example 1:
//
//Input: [-4,-1,0,3,10]
//Output: [0,1,9,16,100]
//Example 2:
//
//Input: [-7,-3,2,3,11]
//Output: [4,9,9,49,121]
//
//
//Note:
//<= A.length <= 10000
//-10000 <= A[i] <= 10000
//A is sorted in non-decreasing order.

#include <vector>
#include <iostream>

using namespace std;


class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    vector<int> answer(A.size(), 0);
    int l = 0, r = A.size() - 1;
    int left, right;

    while (l <= r)
    {
        left = abs(A[l]);
        right = abs(A[r]);
        if (left < right)
        {
            answer[r - l] = right * right;
            r -= 1;
        }
        else
        {
            answer[r - l] = left * left;
            l += 1;
        }
    }

    return answer;
  }
};


int main()
{
    int a[] = {-4, -1, 0, 3, 10};
    Solution solu;
    vector<int> vec_arr(a, a+4);
    vector<int> ret = solu.sortedSquares(vec_arr);
    for (int i = 0; i < ret.size(); ++i)
    {
        cout << ret[i] << " ";
    }

    return 0;
}
