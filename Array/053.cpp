/*
Given an integer array nums, 
find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, which is more subtle.
*/

/*
思路，o(n) 
最直接的方法是遍历所有子数组，复杂度是o(n^2)
网上的方法：
方法1：https://www.geeksforgeeks.org/divide-and-conquer-maximum-sum-subarray/
利用分而治之的方法
将数组分为2分，则结果会出现在左半部分，右半部分或者跨越中间的某个区间
再对左半部分，右半部分递归地进行上述操作。

方法2：https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
利用一个特殊的算法：
对于一个数组A[0, ... ,i - 1]，假设已经找到解。则对于它的拓展数组A[0, ..., i]
的解，分两种情况，要么解仍然和A[0, ... ,i - 1]的解（当前解）相同，要么新的尾端解（包含A[i]）。
这取决于当前解和新的尾端解（包含A[i]）相互之间大小关系。

新的尾端解的确定： 比较当前尾端解+A[i] 和 A[i]的大小关系，取最大值
*/

#include <vector>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int max(int a, int b, int c){
    return max(max(a, b), c);
}

int maxMiddleSum(vector<int>& nums, int low, int mid, int hi){
    int sum = 0;
    int maxSumLeft = INT_MIN;    
    for(int i = mid; i >= low; i--)
    {
        sum += nums[i];
        if(sum > maxSumLeft){
            maxSumLeft = sum;
        }
    }
    sum = 0;
    int maxSumRight = INT_MIN;    
    for(int i = mid + 1; i <= hi; i++)
    {
        sum += nums[i];
        if(sum > maxSumRight){
            maxSumRight = sum;
        }
    }

    return maxSumLeft + maxSumRight;
}

int maxSubArrayRegion(vector<int>& nums, int low, int hi)
{
    if(low == hi){
        return nums[low];
    }
    int mi = (low + hi) / 2;

    int max_l = maxSubArrayRegion(nums, low, mi);
    int max_r = maxSubArrayRegion(nums, mi + 1, hi);

    int max_middle = maxMiddleSum(nums, low, mi, hi);

    return max(max_l, max_r, max_middle);
    
}


int maxSubArray_m1(vector<int>& nums) {
    return maxSubArrayRegion(nums, 0, nums.size()-1);
}




int maxSubArray_m2(vector<int>& nums) {
    int maxSince = nums[0]; //未拓展前的解
    int maxEnd = nums[0]; //尾端解
    
    for(size_t i = 1; i < nums.size(); i++)
    {
        maxEnd = max(maxEnd + nums[i], nums[i]);
        if(maxEnd > maxSince){
            maxSince = maxEnd;
        }
    }

    return maxSince;
}



int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray_m1(nums) << endl;
    return 0;
}