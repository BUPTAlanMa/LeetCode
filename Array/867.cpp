 /*
Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix. 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
 

Note:

1 <= A.length <= 1000
1 <= A[0].length <= 1000
 */
 
#include <vector>
 using namespace std;

 vector<vector<int>> transpose(vector<vector<int>> &A){
     size_t row = A.size();
     size_t column = A[0].size();
     vector<vector<int>> result(column);
     for (size_t i = 0; i < column; i++){         
         for(size_t j = 0; j < row; j++) {
             result[i].push_back(A[j][i]);
         }        
     }

     return result;
 };

 int main(int argc, char const *argv[])
 {
     vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
     transpose(A);
     return 0;
 }
 