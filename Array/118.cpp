/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <vector>
#include <cassert>
using namespace std;


// ¿¼ÂÇ¶Ô³ÆÐÔ
bool getNextRow(vector<int>& lastRow, vector<int>& result)
{
    if(lastRow.size() > 1){
        if(lastRow.size() == 1){
            result = {1, 1};
            return true;
        }            
        else{
            result = vector<int>(lastRow.size() + 1);
            result[0] = 1;
            for(size_t i = 1; i <= result.size() / 2; i++)
            {
                result[i] = lastRow[i - 1] + lastRow[i];
            }
            int lo = 0;
            int hi = result.size() - 1;
            while(lo < hi){
                result[hi--] = result[lo++];
            }
            return true;
        }
    }
    return false;
}


vector<vector<int>> generate(int numRows) {
    if(numRows < 1){
        return {};
    }
    if(numRows == 1)
        return {{1}};
    if(numRows == 2)
        return {{1}, {1,1}};

    vector<vector<int>> result(numRows);
    result[0] = {1};
    result[1] = {1, 1};
    int i = 2;
    while(i < numRows){
        getNextRow(result[i - 1], result[i]);
        i++;
    }

    return result;
}


int main(){    
    vector<vector<int>> result = generate(5);
    system("pause");
    return 0;
}