/*
18. 4Sum

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include <vector>
#include <algorithm>

using namespace std;

/**
 * ���������⣬תΪ����
 * ����������תΪ����
 */
vector<vector<int>> fourSum(vector<int>& nums, int target) {    
    if(nums.size() < 4)
        return {};
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int sub_sum;
    for(int i = 0; i < nums.size() - 3; i++)
    {
        sub_sum = target - nums[i];
        // ��������
        for(int j = i + 1; j < nums.size() - 2; j++)
        {
            sub_sum = target - nums[i] - nums[j];
            // ��������
            int lo = j + 1;
            int hi = nums.size() - 1;
            int twoSum;
            while(lo < hi){
                twoSum = nums[lo] + nums[hi];
                if(twoSum < sub_sum)
                    lo++;
                else if(twoSum > sub_sum)
                    hi--;
                else{
                    result.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                    // ȥ��
                    int lo_val = nums[lo];
                    while(lo < hi && nums[lo] == lo_val)
                        ++lo;
                    int hi_val = nums[hi];
                    while(lo < hi && nums[hi] == hi_val)
                        --hi;
                }                
            }          
            int cur_val = nums[j];
            while(j + 1 < nums.size() - 2 && nums[j + 1] == cur_val)
                ++j;
        }
        int cur_val = nums[i];
        while(i + 1 < nums.size() - 3 && nums[i + 1] == cur_val)
            ++i;
    }

    return result;
}

int main(){
    vector<int> nums = {-5,-4,-3,-2,-1,0,0,1,2,3,4,5};
    vector<vector<int>> result = fourSum(nums, 0);
    return 0;
}