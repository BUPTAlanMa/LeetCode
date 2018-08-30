/*
Given an integer array nums, 
find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, which is more subtle.
*/

/*
˼·��o(n) 
��ֱ�ӵķ����Ǳ������������飬���Ӷ���o(n^2)
���ϵķ�����
����1��https://www.geeksforgeeks.org/divide-and-conquer-maximum-sum-subarray/
���÷ֶ���֮�ķ���
�������Ϊ2�֣��������������벿�֣��Ұ벿�ֻ��߿�Խ�м��ĳ������
�ٶ���벿�֣��Ұ벿�ֵݹ�ؽ�������������

����2��https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
����һ��������㷨��
����һ������A[0, ... ,i - 1]�������Ѿ��ҵ��⡣�����������չ����A[0, ..., i]
�Ľ⣬�����������Ҫô����Ȼ��A[0, ... ,i - 1]�Ľ⣨��ǰ�⣩��ͬ��Ҫô�µ�β�˽⣨����A[i]����
��ȡ���ڵ�ǰ����µ�β�˽⣨����A[i]���໥֮���С��ϵ��

�µ�β�˽��ȷ���� �Ƚϵ�ǰβ�˽�+A[i] �� A[i]�Ĵ�С��ϵ��ȡ���ֵ
*/

#include <vector>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int max(int a, int b, int c){
    return max(max(a, b), c);
}

int maxMiddleSum(vector<int>& nums, int low, int mid, int hi){
    int sum = 0;
    int maxSumLeft = INT_MIN;    
    for(int i = mid; i >= low; i--)
    {
        sum += nums[i];
        if(sum > maxSumLeft){
            maxSumLeft = sum;
        }
    }
    sum = 0;
    int maxSumRight = INT_MIN;    
    for(int i = mid + 1; i <= hi; i++)
    {
        sum += nums[i];
        if(sum > maxSumRight){
            maxSumRight = sum;
        }
    }

    return maxSumLeft + maxSumRight;
}

int maxSubArrayRegion(vector<int>& nums, int low, int hi)
{
    if(low == hi){
        return nums[low];
    }
    int mi = (low + hi) / 2;

    int max_l = maxSubArrayRegion(nums, low, mi);
    int max_r = maxSubArrayRegion(nums, mi + 1, hi);

    int max_middle = maxMiddleSum(nums, low, mi, hi);

    return max(max_l, max_r, max_middle);
    
}


int maxSubArray_m1(vector<int>& nums) {
    return maxSubArrayRegion(nums, 0, nums.size()-1);
}




int maxSubArray_m2(vector<int>& nums) {
    int maxSince = nums[0]; //δ��չǰ�Ľ�
    int maxEnd = nums[0]; //β�˽�
    
    for(size_t i = 1; i < nums.size(); i++)
    {
        maxEnd = max(maxEnd + nums[i], nums[i]);
        if(maxEnd > maxSince){
            maxSince = maxEnd;
        }
    }

    return maxSince;
}



int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray_m1(nums) << endl;
    return 0;
}