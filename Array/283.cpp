/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include <vector>
#include <iostream>
#include <iterator>

using namespace std;
// ˼·��ע��Ҫ���ܿ������飬�Ҳ�����������
// ʹ��������ǣ���ʶ0Ԫ������������յ㣬Ȼ�󽻻�λ����Ȼ����Ԫ���ƶ���
void moveZeroes(vector<int>& nums) {
    int zero_index = 0;
    int nonzero_index = 0; //nonzero_index >= zero_index
    int len = nums.size();
    while (zero_index < len) { //ÿ������һ�ԣ�len���Ը��Ŷ�̬��1
        if(nums[zero_index] != 0){
            zero_index += 1;
        }
        if(nums[nonzero_index] != 0){
            using std::swap;
            swap(nums[zero_index], nums[nonzero_index]);
            zero_index += 1;
            nonzero_index = zero_index + 1;            
        }
        else{
            nonzero_index += 1;
            if(nonzero_index >= len)
                break;
        }
    }
    copy(nums.cbegin(), nums.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

// ͬ����˼·��������д��
void moveZeroes_v2(vector<int>& nums) {
    for(int zero_index = 0, none_zero_index = 0;  
        none_zero_index < nums.size() && zero_index < nums.size();) {  

        if(nums[zero_index] != 0) {  
            zero_index++;  
            none_zero_index = zero_index;  
            continue;  
        }   
        if(nums[none_zero_index] == 0) {  
            none_zero_index++;  
            continue;  
        }  
        int temp = nums[zero_index];  
        nums[zero_index] = nums[none_zero_index];  
        nums[none_zero_index] = temp;  
        zero_index++;  
        none_zero_index++;  
    }  
    copy(nums.cbegin(), nums.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}  


int main(){

    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes_v2(nums);
    return 0;
}