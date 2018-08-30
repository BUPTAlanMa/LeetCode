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
// 这种解法是去找目标矩阵的每一行在源矩阵的位置，进行拷贝，太复杂。
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

    int src_c = nums[0].size();
        
    // 输入检查，能否满足reshape的条件
    if(r * c != nums.size() * src_c || r < 1 || c < 1)
        return nums;
    
    vector<vector<int>> result(r);

    int nums_row_index = 0; //记录下次拷贝从哪一行开始
    int nums_column_index = 0; //记录下次拷贝从哪一列开始
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

                if(nums_column_index + c > src_c) //此行需要从src的当前行和下一行拷贝
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

// 先将源矩阵转为一维向量，找坐标对应关系。
vector<vector<int>> matrixReshape_v2(vector<vector<int>>& nums, int r, int c) {
    int src_c = nums[0].size();
    int src_r = nums.size(); 
    // 输入检查，能否满足reshape的条件
    if(r * c != src_r * src_c || r < 1 || c < 1)
        return nums;
    
    vector<vector<int>> result(r, vector<int>(c));

    int k = 0;
    for(int i = 0; i < r; i++) {
        
        for(int j = 0; j < c; j++)
        {
            // 等效在一维向量中的坐标
            k = i * c + j;
            result[i][j] = nums[k / src_c][k % src_c];
        }
        
    }

    return result;

}

// 更简洁的版本, 只使用一维坐标，推导出二维坐标
vector<vector<int>> matrixReshape_v3(vector<vector<int>>& nums, int r, int c) {
    int src_c = nums[0].size();
    int src_r = nums.size(); 
    // 输入检查，能否满足reshape的条件
    if(r * c != src_r * src_c || r < 1 || c < 1)
        return nums;
    
    vector<vector<int>> result(r, vector<int>(c));

    int k = 0;
    for(int i = 0; i < r * c; i++) {        
            // 等效在一维向量中的坐标
            result[i / c][i % c] = nums[i / src_c][i % src_c];
    }

    return result;

}

int main(){
    vector<vector<int>> nums = {{1, 2}, {3, 4}};
    matrixReshape(nums, 4, 1);
    return 0;
}