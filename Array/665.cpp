/*
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].
*/


#include <vector>

using namespace std;


/*�ο��ⷨ�еĵ����ַ�����
1. �ȼ��pivot��ĸ������������1������false.�϶����Ϸ�
2. ���pivot����Ϊ1����λ��Ϊp.�������
2.1 p = 0,ֻ���޸ĵ�һ��Ԫ�أ�����true
2.2 p = size() - 2. �����ڶ���Ԫ�أ�ֻ���޸����һ��Ԫ�ؼ���
2.3 ����p, p-1, p+1, p+2.����ܱ�֤A[p-1] <= A[p+1]����A[p] <= A[p+2] 
*/

bool checkPossibility(vector<int>& nums) {
    if(nums.size() < 2){
        return true;
    }
    int num = 0; //pivot����
    for(size_t i = 0; i < nums.size() - 1; i++)
    {
        if(nums[i] > nums[i+1]){
            num += 1; 
            if(num > 1){
                return false;
            }
        
            // ��pivot����
            if(i == 0 || i == (nums.size() - 2)){
                ;
            }
            else{
                if(nums[i - 1] > nums[i + 1] && (i + 2 < nums.size() && nums[i] > nums[i + 2]))
                    return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int> nums = {3,4,2,3};
    // [3,4,2,3]
    // [1,5,4,6,7,10,8,9]
    // [2,3,3,2,4]
    // [1,2,4,5,3] ֻ������һ��
    // [1,3,4,2,5]
    // [3,4,2,3]
    bool result = checkPossibility(nums);
    return 0;
}