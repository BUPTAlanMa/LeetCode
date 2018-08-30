/*
581. Shortest Unsorted Continuous Subarray

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

#include <vector>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <climits>

using namespace std;

// ��ֱ�ӵĽⷨ��3.99%
/*
ȷ���߽�
1. ������ˣ�����ǰԪ���Ƿ��и�С��ֵ�����ڸ�ֵ�ұߡ�
2. �����Ҷˣ�����ǰԪ���Ƿ��и����ֵ�����ڸ�ֵ��ߡ�
*/
/*
int findUnsortedSubarray(vector<int>& nums) {
    // ���
    int left_bound = 0;
    bool stop = false;
    int i = 0;
    for(i = 0; i < nums.size(); i++)
    {   
        for(int j = i + 1; j < nums.size(); j++)
        {
            if(nums[j] < nums[i]){
                stop = true;
                break;
            }                 
        }   
        if(stop)
            break;
    }
    left_bound = i;
    if(left_bound == nums.size())
        return 0;

    // �ұ�
    int right_bound = nums.size() - 1;
    stop = false;
    for(i = nums.size() - 1; i >= 0; i--)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(nums[j] > nums[i]){
                stop = true;
                break;
            }                 
        }   
        if(stop)
            break;
    }
    right_bound = i;

    return right_bound - left_bound + 1;
}
*/

/*
7.16%
����2�� �Ը����������򣬱Ƚ϶�ӦԪ�ز���ȵ����˵������±�
*/
/*
int findUnsortedSubarray(vector<int>& nums) {
    vector<int> nums_copy(nums.begin(), nums.end());
    sort(nums_copy.begin(), nums_copy.end());
    // ����߲���Ԫ��
    int left_bound = 0;
    int i = 0;
    for(i = 0; i < nums.size(); i++)
    {   
        if(nums[i] != nums_copy[i])
            break;
    }
    left_bound = i;
    if(left_bound == nums.size())
        return 0;

    // �ұ�
    int right_bound = nums.size() - 1;
    for(i = nums.size() - 1; i >= 0; i--)
    {
        if(nums[i] != nums_copy[i]) 
            break;
    }
    right_bound = i;

    return right_bound - left_bound + 1;
}
*/

/*
59.57%
����3��ʹ��ջ
ʱ�临�Ӷ�o(n)
*/
/*
int findUnsortedSubarray(vector<int>& nums) {
    stack<int> s;
    int l = nums.size(), r = 0; //��������Ľ�ֹλ�ã����ұ����Ľ�ֹλ��
    for (int i = 0; i < nums.size(); i++) {
        while (!s.empty() && nums[s.top()] > nums[i]){
            l = min(l, s.top());
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] < nums[i]){
            r = max(r, s.top());
            s.pop();
        }            
        s.push(i);
    }
    return r - l > 0 ? r - l + 1 : 0;
}
*/

/*
����4����ʹ�ö���ռ䣬���Ӷ�Ϊo(n)
*/
int findUnsortedSubarray(vector<int>& nums) {
    int minimum = INT_MAX, maximum = INT_MIN;
    bool flag = false;
    // ��Сֵ
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1])
            flag = true;
        if (flag)
            minimum = min(minimum, nums[i]);
    }
    // ���ֵ
    flag = false;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] > nums[i + 1])
            flag = true;
        if (flag)
            maximum = max(maximum, nums[i]);
    }

    int l, r;
    for (l = 0; l < nums.size(); l++) {
        if (minimum < nums[l])
            break;
    }
    for (r = nums.size() - 1; r >= 0; r--) {
        if (maximum > nums[r])
            break;
    }
    return r - l < 0 ? 0 : r - l + 1;
}

int main(){
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    // {2, 6, 4, 8, 10, 9, 15}
    int result = findUnsortedSubarray(nums);
    return 0;
}