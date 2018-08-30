/*
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
Output: True
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:

Input:
matrix = [
  [1,2],
  [2,2]
]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.

Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].
*/

#include <vector>
#include <iostream>
using namespace std;

// ˼·���ֱ����з���((0, 0), (0, 1), ...)���з���((1, 0), (2, 0), ...)���
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    size_t rows = matrix.size();
    size_t columns = matrix[0].size();

    // �Խ�����Ԫ��ֵ
    int value;
    // Ҫ����Ԫ��λ������
    size_t row_index = 0;
    size_t column_index = 0;
    for(size_t i = 0; i < columns; i++)
    {
        value = matrix[0][i];
        row_index = 0;
        column_index = i;
        while(++row_index < rows && ++column_index < columns){
            if(matrix[row_index][column_index] != value)
                return false;
        }
    }
    for(size_t j = 1; j < rows; j++)
    {
        value = matrix[j][0];
        row_index = j;
        column_index = 0;
        while(++row_index < rows && ++column_index < columns){
            if(matrix[row_index][column_index] != value)
                return false;
        }
    }

    return true;
}

int main() {
  cout << "The Input Matrix " << (isToeplitzMatrix ? "is " : "is not ")
                                                               << " ToeplitzMatrix" << endl;
  return 0;
}