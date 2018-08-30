/*
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*/

#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

// ����1���������sumΪint,����ת����ķѸ���ʱ��
/*
double findMaxAverage(vector<int>& nums, int k) {
    double sum = 0;    
    for(size_t i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    double newSum = sum;
    for(size_t i = 1; i <= nums.size() - k; i++)
    {
        newSum = newSum - nums[i - 1] + nums[i + k - 1];
        if(newSum > sum){
            sum = newSum;
        }
    }
    return sum / k;
}
*/
/*
// ������д��
double findMaxAverage(vector<int>& nums, int k) {
    double sum=0, res=INT_MIN;
    for(int i=0;i<nums.size();i++) {
        if(i<k) sum+=nums[i];
        else {
            res=max(sum, res);
            sum+=nums[i]-nums[i-k];
        }
    }
    res=max(sum, res);
    return res/k;
}
*/

// ����2���ۼӺ�
/*
����Ԫ�ص��ۼӺ�����sum[]
Ȼ��k�����ڵ�����ĺͣ�����sum[i] - sum[i - k]
*/
double findMaxAverage(vector<int>& nums, int k) {
    vector<double> sum(nums.size());    
    for(size_t i = 0; i < nums.size(); i++)
    {
        if(i == 0)
            sum[i] = nums[i];
        else
            sum[i] = sum[i - 1] + nums[i];
    }
    // �Ƚ�k����������ĺ�
    double max_sum = sum[k - 1];
    for(size_t i = k; i < sum.size(); i++)
    {
        max_sum = max(sum[i] - sum[i - k], max_sum);
    }

    return max_sum / k;
}

int main(){
    // 1, 12, -5, -6, 50, 3,  k=3 / 12.75
    //0, 4, 0, 3, 2, k=1  
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    double result = findMaxAverage(nums, 3);
    system("pause");
    return 0;
}