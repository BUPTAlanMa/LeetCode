/*
697. Degree of an Array

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

*/

#include <vector>
#include <iterator>
#include <map>
#include <iostream>
#include <utility> //֧��make_pair

using namespace std;
// ˼·����ʵ���Ұ������ִ������Ԫ�أ����ܲ�ֹһ���������������󳤶�
// ʹ���ֵ䣬keyΪԪ��ֵ��valueΪ��ֹλ��, Ԫ�ظ�����
int findShortestSubArray(vector<int>& nums) {
    map<int, vector<int>> record;
    int maxNum = 1;
    int shortestSubArrayLen = 1;
    vector<int> itemValue(3, 0); //�ֵ��ֵ
    for (size_t i = 0; i < nums.size(); i++){
        if(record.find(nums[i]) != record.end()){
            itemValue = record[nums[i]];
            itemValue[1] = i; //������ֹλ��
            itemValue[2] += 1; //��������
            record[nums[i]] = itemValue;
            if(itemValue[2] >= maxNum){  //������ȡ����ִ�������Ԫ��ֵ��ֹһ��                
                if(itemValue[2] == maxNum){
                    int tmp = itemValue[1] - itemValue[0] + 1;
                    if(tmp < shortestSubArrayLen)
                        shortestSubArrayLen = tmp;
                    continue;
                }
                maxNum = itemValue[2];
                shortestSubArrayLen = itemValue[1] - itemValue[0] + 1;
            }                
        }        
        else
        {
            itemValue.assign({i, i, 1});
            record.insert(make_pair(nums[i], itemValue));
        }


    }

    return shortestSubArrayLen;
}

int main(){
    vector<int> nums = {1,1,2,2,2,1};
    int shortestSubArrayLen = findShortestSubArray(nums);
    cout << shortestSubArrayLen << endl;
    return 0;
}