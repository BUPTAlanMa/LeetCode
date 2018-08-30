/*
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
*/

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
// ���ֽⷨ��ȥ��Ŀ������ÿһ����Դ�����λ�ã����п�����̫���ӡ�
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

    int src_c = nums[0].size();
        
    // �����飬�ܷ�����reshape������
    if(r * c != nums.size() * src_c || r < 1 || c < 1)
        return nums;
    
    vector<vector<int>> result(r);

    int nums_row_index = 0; //��¼�´ο�������һ�п�ʼ
    int nums_column_index = 0; //��¼�´ο�������һ�п�ʼ
    for (int i = 0; i < r; i++) {

        if(c ==  src_c) {
            result[i] = nums[i];
        }          
        else {
            vector<int> curr_row(c);  
            if(c > src_c){
                int copyed_item_num = 0;
                auto last = curr_row.begin();
                while(copyed_item_num + src_c < c){
                    if(nums_column_index != 0){                        
                        last = copy(nums[nums_row_index].begin() + nums_column_index, 
                                    nums[nums_row_index].end(), last);
                        copyed_item_num += src_c - nums_column_index;
                        nums_row_index += 1;
                        nums_column_index = 0;
                        
                        continue;
                    }

                    last = copy(nums[nums_row_index].begin(), nums[nums_row_index].end(), last);
                    copyed_item_num += src_c;
                    nums_row_index += 1;
                }
                last = copy(nums[nums_row_index].begin(), 
                            nums[nums_row_index].begin() + c - copyed_item_num, last);
                nums_column_index += c - copyed_item_num;
                if (nums_column_index == src_c) {
                    nums_row_index += 1;
                    nums_column_index = 0;
                }
            }
            else{

                if(nums_column_index + c > src_c) //������Ҫ��src�ĵ�ǰ�к���һ�п���
                {
                    auto last = curr_row.begin();
                    int copyed_item_num = 0;
                    last = copy(nums[nums_row_index].begin() + nums_column_index, 
                                nums[nums_row_index].end(), last);
                    nums_row_index += 1;                        
                    copyed_item_num += src_c - nums_column_index;
                    nums_column_index = 0;
                    last = copy(nums[nums_row_index].begin(), 
                                nums[nums_row_index].begin() + c - copyed_item_num, last);
                    nums_column_index += c - copyed_item_num;
                }
                else{
                    copy(nums[nums_row_index].begin() + nums_column_index, 
                        nums[nums_row_index].begin() + nums_column_index + c, curr_row.begin());
                    nums_column_index += c;
                }  
                if (nums_column_index == src_c) {
                        nums_row_index += 1;
                        nums_column_index = 0;
                }

            }

            result[i] = curr_row;
        }

    }

    return result;
}

// �Ƚ�Դ����תΪһά�������������Ӧ��ϵ��
vector<vector<int>> matrixReshape_v2(vector<vector<int>>& nums, int r, int c) {
    int src_c = nums[0].size();
    int src_r = nums.size(); 
    // �����飬�ܷ�����reshape������
    if(r * c != src_r * src_c || r < 1 || c < 1)
        return nums;
    
    vector<vector<int>> result(r, vector<int>(c));

    int k = 0;
    for(int i = 0; i < r; i++) {
        
        for(int j = 0; j < c; j++)
        {
            // ��Ч��һά�����е�����
            k = i * c + j;
            result[i][j] = nums[k / src_c][k % src_c];
        }
        
    }

    return result;

}

// �����İ汾, ֻʹ��һά���꣬�Ƶ�����ά����
vector<vector<int>> matrixReshape_v3(vector<vector<int>>& nums, int r, int c) {
    int src_c = nums[0].size();
    int src_r = nums.size(); 
    // �����飬�ܷ�����reshape������
    if(r * c != src_r * src_c || r < 1 || c < 1)
        return nums;
    
    vector<vector<int>> result(r, vector<int>(c));

    int k = 0;
    for(int i = 0; i < r * c; i++) {        
            // ��Ч��һά�����е�����
            result[i / c][i % c] = nums[i / src_c][i % src_c];
    }

    return result;

}

int main(){
    vector<vector<int>> nums = {{1, 2}, {3, 4}};
    matrixReshape(nums, 4, 1);
    return 0;
}