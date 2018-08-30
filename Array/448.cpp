/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

// 思路，最直观的方法是排序，但是要求o(n)的时间复杂度
// 同时不能使用额外空间，意味着不能使用辅助的变量（字典）
// 题目提示可以利用返回值vector<int> 
vector<int> findDisappearedNumbers(vector<int>& nums) {
    size_t len = nums.size();
    vector<int> result(len, 0);

    for (int i = 0; i < len; i++){
        result[nums[i] - 1] = 1; //标记出现的元素
    }
    // copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    // cout << endl;
    // 将缺失的元素放置在向量最后
    for(int i = 0; i < len; i++){
        if(result[i] == 0)
            result.push_back(i + 1);
    }
    // // 删除缺失元素之前的全部元素( < n)   
    result.erase(result.begin(), result.begin() + len);  
    return result; 


}

int main(){
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = findDisappearedNumbers(nums);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    return 0;
}