/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int p = -1; // 指向连续的1中，起始1的位置
    int isConsecutive = false;
    int maxNum = 0;
    for (int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            if(!isConsecutive)
                p = i;
            isConsecutive = true;   
        }  
        else
            isConsecutive = false;  

        if(isConsecutive){
            maxNum = max(maxNum, i - p + 1);  
        }
    }
    return maxNum;

}

// 简化版
int findMaxConsecutiveOnes_v2(vector<int>& nums) {
    int maxNum = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            sum = 0;
            maxNum = max(maxNum, sum);  
        }         
        else
            sum += 1;
    }
    return maxNum;

}

// 网上更快的版本
int findMaxConsecutiveOnes_v3(vector<int>& nums) {
    int res = 0, sum = 0;
    for (int num : nums) {
        sum = (sum + num) * num;
        res = max(res, sum);
    }
    return res;
}

int main() {
    vector<int> nums = {1,1,0,1,1,1};
    cout << findMaxConsecutiveOnes(nums);
    return 0;
}