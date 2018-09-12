/*
16. 3Sum ClosestGiven 
an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * 1. 排序
 * 2. 遍历第一个数，第二、三数初始化为第一个数之后区间的首尾，求三数之和
 * 3. 如果新三数之和更接近target,更新。同时判断新的三数之和跟target的大小关系
 * 3.1 如果新三数之和大于target,则第三个数向前取。否则，第二个数向后取
 */

int threeSumClosest(vector<int>& nums, int target) {
   if(nums.size() < 3)
       return {};
   sort(nums.begin(), nums.end());
   int first = 0;
   int second = 1;
   int third = 2;
   int result = nums[first] + nums[second] + nums[third];
   int new_sum;
   for(size_t i = 0; i < nums.size() - 2; i++)
   {
       first = i;
       second = i + 1;
       third = nums.size() - 1;       
       while(second < third){
           new_sum = nums[first] + nums[second] + nums[third];
           if(abs(new_sum - target) < abs(result - target)){
               result = new_sum;
               if(result == target)
                   return target;
           }
           new_sum > target ? --third : ++second;
       }
   }

   return result;
}

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int result = threeSumClosest(nums, 1);
    return 0;
}