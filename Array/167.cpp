/*
167. Two Sum II - Input array is sorted
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/

#include <vector>
#include <iterator>
#include <iostream>

using namespace std;


// 思路，利用两个首尾索引，二分查找
int binarySearch(vector<int>&numbers, int target, int lo, int hi){
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(numbers[mid] == target)
            return mid;
        if(numbers[mid] > target)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result(2, -1);
    for (size_t i = 0; i < numbers.size(); i++){
        if(numbers[i] > target)
            break;
        int index = binarySearch(numbers, target - numbers[i], i + 1, numbers.size() - 1);
        if(index != -1){
            result[0] = i + 1;
            result[1] = index + 1;
            return result; // only one solution
        }
    }

    return result;
}

int main(){
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    return 0;
}