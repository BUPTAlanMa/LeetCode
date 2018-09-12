#include <vector>
#include <iostream>

using namespace std;


void maxPathNum_internal(vector<vector<int> >& matrix, int i, int j, int& result){
    int N = matrix.size();
    if(i >= N || j >= N)
        return ;
    if(matrix[i][j]){
        result++;
        maxPathNum_internal(matrix, i, j + 1, result);
        maxPathNum_internal(matrix, i + 1, j, result);
    }        
    else{
        maxPathNum_internal(matrix, i + 1, j, result);
        maxPathNum_internal(matrix, i, j + 1, result);
    }
        
}; 

int maxPathNum(vector<vector<int> >& matrix){
    int result = 0;
    maxPathNum_internal(matrix, 0, 0, result);
    return result;
}; 

int main(){
    int N;
    cin >> N;

    vector<vector<int>> matrix(N);
    
    
    for(size_t i = 0; i < N; i++)
    {
        vector<int> row(N, 0);
        matrix[i] = row;
    }
    int M_row, col;
    cin >> M_row >> col;
    while(M_row--){
        int row;
        int col;
        cin >> row >> col;
        matrix[row][col] = 1;
    }
    cout << maxPathNum(matrix);
    
    return 0;
}