/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

 

Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15
*/

#include <vector>

using namespace std;

bool isMagicSquare(vector<vector<int>>& grid, int rowStart, int columnStart) 
{
    // 检查是否所有元素位于1到9    
    for(size_t i = rowStart; i < rowStart + 3; i++)    {
        
        for(size_t j = columnStart; j < columnStart + 3; j++)
        {
            if(grid[i][j] < 1 || grid[i][j] > 9)
                return false;
        }
        
    }

    int target = grid[rowStart][columnStart] + grid[rowStart][columnStart + 1] + grid[rowStart][columnStart + 2];
    int sum;
    // 行
    for(size_t i = 1; i < 3; i++)
    {
        sum = grid[rowStart + i][columnStart] + grid[rowStart + i][columnStart + 1] + grid[rowStart + i][columnStart + 2];
        if(sum != target){
            return false;
        }
    }
    // 列
    for(size_t i = 1; i < 3; i++)
    {
        sum = grid[rowStart][columnStart + i] + grid[rowStart + 1][columnStart + i] + grid[rowStart + 2][columnStart + i];
        if(sum != target){
            return false;
        }
    }
    // 对角线
    sum = grid[rowStart][columnStart] + grid[rowStart + 1][columnStart + 1] + grid[rowStart + 2][columnStart + 2];
    if(sum != target)
        return false;
    sum = grid[rowStart + 2][columnStart] + grid[rowStart + 1][columnStart + 1] + grid[rowStart][columnStart + 2];
    if(sum != target)
        return false;
    return true;

}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int num = 0;
    if(grid.size() < 3 || grid[0].size() < 3)
        return 0;
    for(size_t i = 0; i <= grid.size() - 3; i++)
    {        
        for(size_t j = 0; j <= grid[0].size() - 3; j++)
        {
            if(isMagicSquare(grid, i, j))
                num += 1;
        }        
    }

    return num;
}

int main(){
    vector<vector<int>> grid = {{7,6,2,2,4},
                            {4,4,9,2,10},
                            {9,7,8,3,10},
                            {8,1,9,7,5},
                            {7,10,4,11,6}};
    // [[8,1,6],[3,5,7],[4,9,2]]
    // [[10,3,5],[1,6,11],[7,9,2]]
    // [[7,6,2,2,4],[4,4,9,2,10],[9,7,8,3,10],[8,1,9,7,5],[7,10,4,11,6]]
    int result = numMagicSquaresInside(grid); 
    return 0;
}