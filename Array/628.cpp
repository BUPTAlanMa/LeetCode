/*
628. Maximum Product of Three Numbers

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;
/*************δ���ǿ�������******************
// ˼·1������ʱ�临�Ӷ�O(logn),�ռ临�Ӷ�0
int maximumProduct_v1(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    return nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
}
// ˼·2��ʹ�ó���Ϊ3��������¼ǰ�������ֵ��ʱ�临�Ӷ�O(n)���ռ临�Ӷȳ���
void resetMaxThree(vector<int>& maxThree, int num){
    for (int i = 0; i < maxThree.size(); i++){
        if (num > maxThree[i])
            maxThree[i] = num;
    }
}
int maximumProduct_v2(vector<int>& nums) {
    vector<int> maxThree(3, 0);
    for (int i = 0; i < nums.size(); i++){
        resetMaxThree(maxThree, nums[i]);
    }

    return maxThree[0] * nums[1] * nums[2];
}
**********************************************/

// ˼·��������󣬼������һ�������ֵ�϶�Ҫѡ������������ֵ�����������
// 1. ���һ����ǰ������
// 2. ǰ����
int maximumProduct_v1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return max(nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3],
        nums[nums.size() - 1] * nums[0] * nums[1]);    
}

int main(){
    vector<int> nums = {1,2,3,4};
    cout << maximumProduct_v2(nums) << endl;
    
    return 0;
}