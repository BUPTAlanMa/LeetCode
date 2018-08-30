/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/


#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

/**
 * 思路：归并排序中的merge这一步骤
*/

/*
* 方法1：这里的插入元素操作不需要申请size+1的内存，因为后面有冗余的空间
*/
void arrayRightMove(vector<int>& nums, int pos, int value, int shift){
    // shift所需表示移动有效元素个数    
    while(pos < nums.size() && shift >= 0){
        if(pos == nums.size() - 1){
            nums[pos] = value;
            return;
        }
        // bool isPivot = false;
        int tmp = nums[pos];
        nums[pos] = value;
        value = tmp;

        pos++;
        shift--;
    }
       
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // 因为nums1的长度足够容纳所有数组，所以使用in-place操作，不申请新的内存
    int nums1_index = 0;
    int nums2_index = 0;
    while(nums1_index < m && nums2_index < n)
    {
        if(nums2[nums2_index] < nums1[nums1_index]){
            m++;
            arrayRightMove(nums1, nums1_index, nums2[nums2_index], m - nums1_index - 1);
            nums2_index++;
        }        
        else
        {
            nums1_index++;
        }       
        
    }
    while(nums2_index < n){
        nums1[nums1_index++] = nums2[nums2_index++];
    }
        
}

/*
* 别人的最简洁的解法
*/
/*
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, tar = m + n - 1;
    while (j >= 0) {
        nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
}
*/

/*
* 一般情况下的merge排序的merge方法练习,此时nums1没有冗余长度
*/
/*
void merge_for_mergeSort(vector<int>& nums, int lo, int mid, int hi) {
    vector<int> left(mid - lo + 1); 
    vector<int> right(hi - mid);
    for(size_t i = 0; i < left.size(); i++)
    {
        left[i] = nums[lo + i];
    }
    for(size_t i = 0; i < right.size(); i++)
    {
        right[i] = nums[mid + 1 + i];
    }    
    
    int left_index = 0;
    int right_index = 0;
    int region_index = lo;

    while(left_index < left.size() && right_index < right.size()){
        if(left[left_index] <= right[right_index]){
            nums[region_index++] = left[left_index++];
        }        
        else
        {
            nums[region_index++] = right[right_index++];
        }        
    }
    while(left_index < left.size()){
        nums[region_index++] = left[left_index++];
    }
    while(right_index < right.size()){
        nums[region_index++] = right[right_index++];
    }
    
}
*/




int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2,5,6};
    merge(nums1, 3, nums2, 3);
    system("pause");
    return 0;
}