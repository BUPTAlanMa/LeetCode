/*
15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/** 方法1：利用twoSum
 * 
 */

// two sum有两个版本，利用字典的版本不太容易去重。这里改为使用排序的方案
/*
vector<int> twoSum(vector<int>& nums, int lo, int hi, int target){
    map<int, int> record;
    vector<int> result;
    
    
    for(size_t i = lo; i < hi; i++)    
    {
        int sub = target - nums[i];
        if (record.find(sub) != record.end())
        {
            result.push_back(sub);
            result.push_back(nums[i]);
        }
        else{
           record[nums[i]] = i;
        }
    }

    return result;
}
*/

// nums要预先排序，返回全部的不重复的结果
// hi最大为size() - 1
vector<int> twoSum(vector<int>& nums, int lo, int hi, int target){
    vector<int> result;
    int sum;
    while(lo < hi){
        sum = nums[lo] + nums[hi];
        if(sum < target)
            lo++;
        else if(sum > target)
            hi--;
        else{
            int lo_value = nums[lo];
            int hi_value = nums[hi];
            result.push_back(lo_value);
            result.push_back(hi_value);
            // 跳过与当前lo, hi索引的元素值相等的重复解
            while(lo < hi && nums[lo] == lo_value)
                ++lo;
            while(hi > lo && nums[hi] == hi_value)
                --hi;
        }
    }

    return result;
}


vector<vector<int>> threeSum(vector<int>& nums) {
    
    if(nums.size() < 3)
        return {{}};
    
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int target;
    for(size_t i = 0; i < nums.size(); i++)
    {
        target = 0 - nums[i];
        vector<int> res = twoSum(nums, i + 1, nums.size() - 1, target);          
        for(size_t j = 0; j < res.size(); j+=2)
        {
            result.push_back({nums[i], res[j], res[j + 1]});
        }
        int curr = nums[i];
        while(i + 1 < nums.size() && nums[i + 1] == curr)
            ++i;        

    }
    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    return 0;
}