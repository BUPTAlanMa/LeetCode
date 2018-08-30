/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

/* ˼·��
Ҫ��in_place�������������Ѿ�������������ظ�Ԫ�����ڡ�
����ָ�룬��һ��ָ����ǰһ��ָ�벻�ظ���Ԫ�ص�λ�á�Ȼ�󣬺����Ԫ�ؼ���ǰ�ơ�
ע�⣬�ƶ���Ҫ�������鳤�ȣ�begin��endָ������������λ��

*/

/*
int removeDuplicates(vector<int>& nums) {
    //����ָ��
    int newLen = nums.size(); // ��̬�������鳤��
    if(newLen < 2){
        return newLen;
    }
    int begin = 0;
    int end = 1;
    while(end < newLen){
        if(nums[begin] != nums[end]){
            if(begin != end - 1){
                int distance = end - begin - 1;
                newLen -= distance;
                for(size_t i = begin + 1; i < newLen; i++)
                {
                    nums[i] = nums[i + distance];
                }
                begin = end - distance;
                end = begin + 1;
            }
            else{
                begin++;
                end++;
            }         

        }
        else{
            end++;
        }

    }

    return begin + 1;
}
*/

// �Լ�д�ķ������ڸ��ӣ���׼�ⷨ���£�
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    
    for(size_t j = 1; j < nums.size(); j++)
    {
        if(nums[j] != nums[i]){
            nums[++i] = nums[j];
        }
    }

    return i + 1;
}

int main(){
    vector<int> vec = {1,3,2};
    int newLen = removeDuplicates(vec);
    copy(vec.begin(), vec.begin() + newLen, ostream_iterator<int>(cout, " "));

    return 0;
}