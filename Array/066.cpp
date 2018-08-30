/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/

/*
思路：注意进位
*/

#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>

using namespace std;
/* 此方法会溢出，当位数多时。
vector<int> plusOne(vector<int>& digits) {
    int num = 0;
    for(size_t i = 0; i < digits.size(); i++)
    {
        num += digits[i] * (int)pow(10, digits.size() - 1 - i);
    }
    num += 1;
    int len = (int)log10(num) + 1;
    vector<int> result(len);
    
    for(size_t i = 0; i < len; i++)
    {
        result[i] = num / (int)pow(10, len - 1 - i);
        num -= result[i] * pow(10, len - 1 - i);
    }

    return result;

}
*/
vector<int> plusOne(vector<int>& digits) {
    // 是否有进位
    vector<int> result(digits.size());
    bool carryBit = true;
    for(int i = digits.size() - 1; i >= 0; i--)
    {
        if(carryBit){
            if(digits[i] == 9){
                result[i] = 0;
                carryBit = true;
            }
            else{
                result[i] = digits[i] + 1;
                carryBit = false;
            }
        }
        else{
            result[i] = digits[i];
        }
    }
    // 最高位仍有进位
    if(carryBit){
        vector<int> result(digits.size() + 1, 0);
        result[0] = 1;
        return result;
    }

    return result;

}

int main(){
    vector<int> vec = {9,9};
    vector<int> result = plusOne(vec);
    return 0;
}