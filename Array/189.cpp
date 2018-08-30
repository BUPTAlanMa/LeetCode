/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

#include <vector>
#include <cstdlib>

using namespace std;

// ���ַ���
//**�����������������ķ�������ͬ�ģ���������е���һ����������ͨ����ת����õ�����һ��**//


/*
* ����1��k������, o(1)�ռ䣬���Ӷ�o(k*n)
*/
/*
void rightShiftStep(vector<int>& nums){
    int temp = nums.back(); //βԪ��
    for(size_t i = nums.size() - 1; i > 0; i--)
    {
        nums[i] = nums[i - 1];
    }
    nums[0] = temp;
}

void rotate_m1(vector<int>& nums, int k) {
    k = k % nums.size(); //ȡ�࣬��С����Ҫ���ظ�
    while(k--){
        rightShiftStep(nums);
    }    
}
*/

/*
* ����2: ���� (AB)r = (ArBr)r , �ռ临�Ӷ�o(1)��ʱ�临�Ӷ�o(n)
*/
void rotate(vector<int>& nums, int k) {
    // ��ת��벿��
    k = k % nums.size();
    if(k != 0){
        int lo = 0;
        int hi = nums.size() - k - 1;
        while(lo < hi){
            using std::swap;
            swap(nums[lo++], nums[hi--]);
        }
        // ��ת�Ұ벿��
        lo = nums.size() - k;
        hi = nums.size() - 1;
        while(lo < hi){
            using std::swap;
            swap(nums[lo++], nums[hi--]);
        }

        // ��תȫ��
        lo = 0;
        hi = nums.size() - 1;
        while(lo < hi){
            using std::swap;
            swap(nums[lo++], nums[hi--]);
        }
    }
    

}

/*
* ����3��ֱ����λkλ�����ݽ���
* �÷���û����ô�򵥣�û�п��ǹ�Լ�������⡣Juggling method.
* https://www.geeksforgeeks.org/array-rotation/
*/

// �����⣬����n=12{1,...,12}, d=3.��ǰ����ѭ��
/*
void rotate_m3(vector<int>& nums, int k) {
    int i = 0;
    int length = nums.size();
    k = k % length;
    if(k != 0){
        int tmp1 = nums[i]; 
        do{
            i += k;
            i = i % length;
            int tmp2 = nums[i]; // ����λ�õ�ֵ�����ⱻ����
            nums[i] = tmp1;
            tmp1 = tmp2;

        } while (i != 0);
    }

}
*/
/*
int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

void rotate_m3(vector<int>& nums, int k) {
    k = k % nums.size();
    if(k != 0){
        int turns = gcd(nums.size(), k);
        for(size_t i = 0; i < turns; i++)
        {
            int tmp1 = nums[i];
            int j = i;
            while(1)
            {
                j += k;
                j = j % nums.size();
                    
                if (j == i)
                    break;

                int tmp2 = nums[j];
                nums[j] = tmp1;
                tmp1 = tmp2;
            }
            nums[j] = tmp1;
        }
    }    

}
*/

/*
* ����4��ʹ�ö���Ŀռ�洢ǰd��ֵ��Ȼ�󽫺����Ԫ�����Ƶ�ǰ�档�ٰ���ǰ�洢�ķ��ں���
*/
/*
void rotate_m4(vector<int>& nums, int k) {
    int length = nums.size();
    k = k % length;
    if(k != 0){
        vector<int> left_part(length - k);    
        for(size_t i = 0; i < length - k; i++)
        {
            left_part[i] = nums[i];
        }

        for(size_t i = 0; i < k; i++)
        {
            nums[i] = nums[i + length - k];
        }
        
        
        for(size_t i = k; i < length; i++)
        {
            nums[i] = left_part[i - k];
        } 
    }
  

}
*/

/*
����5��Block swap algorithm for array rotation
// ����ķ��������������������
Initialize A = arr[0..d-1] and B = arr[d..n-1]
1) Do following until size of A is equal to size of B

  a)  If A is shorter, divide B into Bl and Br such that Br is of same 
       length as A. Swap A and Br to change ABlBr into BrBlA. Now A
       is at its final place, so recur on pieces of B.  

   b)  If A is longer, divide A into Al and Ar such that Al is of same 
       length as B Swap Al and B to change AlArB into BArAl. Now B
       is at its final place, so recur on pieces of A.

2)  Finally when A and B are of equal size, block swap them.
*/

// /*This function swaps d elements starting at index fi
//   with d elements starting at index si */
// void swap(int arr[], int fi, int si, int d)
// {
//    int i, temp;
//    for(i = 0; i<d; i++)   
//    {
//      temp = arr[fi + i];
//      arr[fi + i] = arr[si + i];
//      arr[si + i] = temp;
//    }     
// } 

// void leftRotate(int arr[], int d, int n)
// { 
//   /* Return If number of elements to be rotated is 
//     zero or equal to array size */ 
//   if(d == 0 || d == n)
//     return;
     
//   /*If number of elements to be rotated is exactly 
//     half of array size */ 
//   if(n-d == d)
//   {
//     swap(arr, 0, n-d, d);   
//     return;
//   }  
     
//  /* If A is shorter*/             
//   if(d < n-d)
//   {  
//     swap(arr, 0, n-d, d);
//     leftRotate(arr, d, n-d);    
//   }    
//   else /* If B is shorter*/             
//   {
//     swap(arr, 0, d, n-d);
//     leftRotate(arr+n-d, 2*d-n, d); /*This is tricky*/
//   }
// }

// // �����汾

int main(){
    vector<int> nums = {1};
    rotate(nums, 2);
    system("pause");
    return 0;
}