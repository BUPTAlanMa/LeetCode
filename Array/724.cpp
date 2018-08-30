/*
724. Find Pivot Index

Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:
Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
Example 2:
Input: 
nums = [1, 2, 3]
Output: -1
Explanation: 
There is no index that satisfies the conditions in the problem statement.
Note:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].
*/

#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

// 思路：模仿二分查找。
int intervalSum(vector<int>& nums, int lo, int hi){
    int sum = 0;
    for (size_t i = lo; i <= hi; i++){
        sum += nums[i];
    }
    return sum;
}
/*----------没考虑元素正负
int pivotIndex(vector<int>& nums) {
    int hi = nums.size() - 1;
    int lo = 0;
    int left_sum = 0;
    int right_sum = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        left_sum = intervalSum(nums, 0, mid - 1);
        right_sum = intervalSum(nums, mid + 1, nums.size() - 1);

        if(left_sum == right_sum)
            return mid;
        if(left_sum > right_sum)
            hi = mid - 1;
        if(left_sum < right_sum)
            lo = mid + 1;
    }

    return -1;
}
*/

// 思路2：一趟遍历。题目的情况包含：左边没有元素或右边没有元素
int pivotIndex(vector<int>& nums) {   
    if(nums.size() < 2)
        return -1;
    int left_sum = 0;
    int right_sum = 0;
    for(size_t i = 1; i < nums.size(); i++)
        right_sum += nums[i];
    
    if(left_sum == right_sum)
        return 0;
    for(size_t i = 1; i < nums.size(); i++){
        left_sum += nums[i - 1];
        right_sum -= nums[i];
        if(left_sum == right_sum)
            return i;
    }

    return -1;
}

int main(){
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    clock_t start = clock();
    double duriation = 0;

    cout << "result: " << pivotIndex(nums) << endl;
    duriation = (clock() - start) / (double)CLOCKS_PER_SEC;

    cout << "time consume(ms): " << duriation << endl;
    return 0;

}
