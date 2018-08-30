/*
532. K-diff Pairs in an Array

Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].
*/

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
using namespace std;

// 方法1： 复杂度o(n*logn). 耗时在排序上
/*
int findPairs(vector<int>& nums, int k) {
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0, j = 0; i < nums.size(); i++) {
        for (j = max(j, i + 1); j < nums.size() && (long) nums[j] - nums[i] < k; j++) ;
        if (j < nums.size() && (long) nums[j] - nums[i] == k) ans++; //不考虑重复
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;  // 不考虑重复
    }
    return ans;
}
*/

// 方法2：暴力搜索，o(n^2)
// 注意，解对不能重复
/*
int findPairs(vector<int>& nums, int k) {
    if(k < 0 || nums.size() < 2)
        return 0;
    set<pair<int, int>> result;
    for(size_t i = 0; i < nums.size(); i++)
    {
        for(size_t j = i + 1; j < nums.size(); j++)
        {

            if(nums[i] - nums[j] == k || nums[i] - nums[j] == -k){
                pair<int, int> solve = nums[i] <= nums[j] ? make_pair(nums[i], nums[j]) : make_pair(nums[j], nums[i]);
                result.insert(solve);
            }
        } 
    }

    return result.size();
}
*/

// 方法3：o(n), 最快
int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;
    unordered_map<int, int> m;
    for (int n : nums) m[n]++;
    int cnt = 0;
    for (auto p : m) {
        if ((!k && p.second > 1)
        || (k && m.count(p.first + k))) ++cnt;
    }
    return cnt;
}

int main(){
    vector<int> nums = {1, 3, 1, 4, 5};
    int result = findPairs(nums, 0);
    return 0;
}