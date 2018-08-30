/*
217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include <vector>
#include <set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    set<int> record;
    int record_len = 0;
    for (int i = 0; i < nums.size(); i++){
        record.insert(nums[i]);
        record_len += 1;
        if(record.size() != record_len){
            return true;
        }
    }

    return false;
}

int main(){
    vector<int> nums = {1,2,3,1};
    bool result = containsDuplicate(nums);
    return 0;
}