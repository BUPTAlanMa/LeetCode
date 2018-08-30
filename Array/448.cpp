/*
Given an array of integers where 1 �� a[i] �� n (n = size of array), some elements appear twice and others appear once.

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

// ˼·����ֱ�۵ķ��������򣬵���Ҫ��o(n)��ʱ�临�Ӷ�
// ͬʱ����ʹ�ö���ռ䣬��ζ�Ų���ʹ�ø����ı������ֵ䣩
// ��Ŀ��ʾ�������÷���ֵvector<int> 
vector<int> findDisappearedNumbers(vector<int>& nums) {
    size_t len = nums.size();
    vector<int> result(len, 0);

    for (int i = 0; i < len; i++){
        result[nums[i] - 1] = 1; //��ǳ��ֵ�Ԫ��
    }
    // copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    // cout << endl;
    // ��ȱʧ��Ԫ�ط������������
    for(int i = 0; i < len; i++){
        if(result[i] == 0)
            result.push_back(i + 1);
    }
    // // ɾ��ȱʧԪ��֮ǰ��ȫ��Ԫ��( < n)   
    result.erase(result.begin(), result.begin() + len);  
    return result; 


}

int main(){
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = findDisappearedNumbers(nums);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    return 0;
}