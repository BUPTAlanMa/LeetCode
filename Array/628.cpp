/*
628. Maximum Product of Three Numbers

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;
/*************未考虑看正负号******************
// 思路1：排序，时间复杂度O(logn),空间复杂度0
int maximumProduct_v1(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    return nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
}
// 思路2：使用长度为3的向量记录前三个最大值。时间复杂度O(n)，空间复杂度常数
void resetMaxThree(vector<int>& maxThree, int num){
    for (int i = 0; i < maxThree.size(); i++){
        if (num > maxThree[i])
            maxThree[i] = num;
    }
}
int maximumProduct_v2(vector<int>& nums) {
    vector<int> maxThree(3, 0);
    for (int i = 0; i < nums.size(); i++){
        resetMaxThree(maxThree, nums[i]);
    }

    return maxThree[0] * nums[1] * nums[2];
}
**********************************************/

// 思路：排序过后，计算最后一个（最大值肯定要选），另外两个值分两种情况：
// 1. 最后一个的前两个。
// 2. 前两个
int maximumProduct_v1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return max(nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3],
        nums[nums.size() - 1] * nums[0] * nums[1]);    
}

int main(){
    vector<int> nums = {1,2,3,4};
    cout << maximumProduct_v2(nums) << endl;
    
    return 0;
}