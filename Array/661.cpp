/*
661. Image Smoother
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
*/
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
// 思路：两个for循环
// 求该点像素值，如果越界，返回-1
int pointValue(vector<vector<int>>& M, int boundary_x, int boundary_y, int x, int y) {
    if(x >=0 && x < boundary_x && y >= 0 && y < boundary_y)
        return M[x][y];        
    return -1;
}
vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    vector<vector<int>> result = M;
    int boundary_x = M.size();
    int boundary_y = M[0].size();
    for (int i = 0; i < boundary_x; i++){
        for (int j = 0; j < boundary_y; j++){
            int sum = 0;
            int num = 0;
            for (int delta_x = -1; delta_x < 2; delta_x++){
                for (int delta_y = -1; delta_y < 2; delta_y++){
                    int tmp = pointValue(M, boundary_x, boundary_y, i + delta_x, j + delta_y);
                    if(tmp != -1){
                        sum += tmp;
                        num += 1;
                    }
                    
                }
            }
            
            result[i][j] = (int)floor(sum * 1.0 / num);
        }
    }
    return result;
}

int main(){
    vector<vector<int>> M = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
    imageSmoother(M);
    return 0;
}