/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <utility>

using namespace std;

// 直接的方法：o(k*n)
/* 依次遍历每个元素，对当前元素，依次比较它的后k个元素，观察是否相等
*/
/*
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    for(int i = 0; i < nums.size(); i++)
    {        
        for(int j = i + 1; j <= k + i; j++)
        {
            if(j >= nums.size())
                break;
            if(nums[i] == nums[j])
                return true;
        }        
    }

    return false;
}

*/
/*
更优的方法, 时间复杂度o(n)
*/
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> record;

    if (k <= 0) return false;
    if (k >= nums.size()) k = nums.size() - 1;

    for(size_t i = 0; i < nums.size(); i++)
    {
        if(i > k){
            record.erase(nums[i - k - 1]);
        }
        if(record.find(nums[i]) != record.end()){
            return true;
        }
        record.insert(nums[i]);
    }
    return false;
}


int main(){
    vector<int> nums = {1,2,3,4,3,1};
    bool result = containsNearbyDuplicate(nums, 3);
    system("pause");
    return 0;
}