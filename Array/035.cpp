/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/


#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

/*
思路： 二分查找
*/

int searchInsert(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size() - 1;

    if(target < nums[low])
        return low;
    if(target > nums[high])
        return high + 1;

    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(nums[mid] == target)
            return mid;
        if(target > nums[mid]){
            if(target < nums[mid + 1])
                return mid + 1;
            low = mid + 1;
        }        
        else
        {
            if(target > nums[mid - 1])
                return mid;
            high = mid - 1;
        }
        
    }

}

int main(){
    vector<int> vec = {1, 3, 5};
    cout << searchInsert(vec, 1);
    return 0;
}