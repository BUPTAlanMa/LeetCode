/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
Note: Length of the array will not exceed 10,000.
*/

#include <vector>
#include <cstdlib>

using namespace std;

// 方法1：统计严格递增区间的元素个数
int findLengthOfLCIS(vector<int>& nums) {
    if(nums.size() < 2)
        return nums.size();
    int maxLength = 0;
    int lo = 0;
    int i = 1;
    for(i = 1; i < nums.size(); i++)
    {
       if(nums[i] <= nums[i - 1]){
           maxLength = max(maxLength, i - lo);
           lo = i;
       }
    }
    maxLength = max(maxLength, i - lo);
    return maxLength;
}

// 更干净的写法：
/*
int findLengthOfLCIS(vector<int>& nums) {
    int res = 0, cnt = 0;
    for(int i = 0; i < nums.size(); i++){
        if(i == 0 || nums[i-1] < nums[i]) res = max(res, ++cnt);
        else cnt = 1;
    }
    return res;
}
*/

int main(){
    vector<int> nums = {1,3,5,6,7};
    int result = findLengthOfLCIS(nums);
    return 0;
}