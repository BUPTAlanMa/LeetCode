/*
888. Fair Candy Swap

Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

 

Example 1:

Input: A = [1,1], B = [2,2]
Output: [1,2]
Example 2:

Input: A = [1,2], B = [2,3]
Output: [1,2]
Example 3:

Input: A = [2], B = [1,3]
Output: [2,3]
Example 4:

Input: A = [1,2,5], B = [2,4]
Output: [5,4]
 

Note:

1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
It is guaranteed that Alice and Bob have different total amounts of candy.
It is guaranteed there exists an answer.
*/

#include <vector>
#include <set>
using namespace std;
/*
vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sum = 0;
    int sumA = 0;
    for(size_t i = 0; i < A.size(); i++)
    {
        sum += A[i];
    }
    sumA = sum;
    for(size_t i = 0; i < B.size(); i++)
    {
        sum += B[i];
    }
    int target = sum / 2; // sum定义为能被2整除
    int diff = sumA - target;
      
    for(size_t i = 0; i < A.size(); i++)
    {        
        for(size_t j = 0; j < B.size(); j++)
        {
            if(A[i] - B[j] == diff){
                return {A[i], B[j]};
            }
        }        
    }     

}
*/
/*
方法2
*/
vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sa = 0, sb = 0;  // sum of A, B respectively
    for (int x: A) sa += x;
    for (int x: B) sb += x;
    int delta = (sb - sa) / 2;
    // If Alice gives x, she expects to receive x + delta

    set<int> setB;
    for (int x: B) setB.insert(x);

    for (int x: A)
        if (setB.count(x + delta))
            return {x, x + delta};
}


int main(){
    return 0;
}