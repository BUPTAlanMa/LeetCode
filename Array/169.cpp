/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

#include <vector>
#include <map>

using namespace std;
// 思路：使用字典，统计对应元素出现的次数，复杂度o(n)
int majorityElement(vector<int>& nums) {
    map<int, int> statistics;
    for (int i = 0; i < nums.size(); i++){
        if(statistics.find(nums[i]) != statistics.end()){
            statistics[nums[i]] += 1;
        }
        else
            statistics[nums[i]] = 1;
            
    }
    int majority_count = -1;
    int majority_value = 0;
    for(const auto &pair : statistics){
        if(pair.second > majority_count){
            majority_count = pair.second;
            majority_value = pair.first;
        }
            
    }
    return majority_value;
}

int main(){
    vector<int> nums = {3,2,3};
    majorityElement(nums);
    return 0;
}