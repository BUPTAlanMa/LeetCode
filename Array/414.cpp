/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
// 方法1：过于复杂.但一般性好
int thirdMax(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<int> unique;
    
    for(size_t i = 0; i < nums.size(); i++)
    {
        unique.insert(nums[i]);
    }

    if(unique.size() < 3)
        return *(--unique.end());
    else{
        int i = 3;
        auto n = unique.end();
        while(i--){
            --n;
        }
        return *n;
    }
}
*/
// 方法2：时间复杂度近似为o(n).当n比较大时，max3的遍历复杂度可以忽略。
int thirdMax(vector<int>& nums) {

    vector<int> max3; // save for maximum three
    for (auto i = nums.begin(); i != nums.end(); ++i)
    {
        if(max3.size() < 3){
            // if is not repet, pushback and correct the position
            bool isRepet = false;
            for(size_t j = 0; j < max3.size(); j++)
            {
                if(*i == max3[j]){
                    isRepet = true;
                    break;
                }
            }
            // put int the correct position
            if(!isRepet){
                max3.push_back(*i);
                for(size_t j = 0; j < (max3.size() - 1); ++j)
                {
                    if(*i > max3[j]){                        
                        for(size_t k = max3.size() - 1; k > j; k--)
                        {
                            max3[k] = max3[k - 1];
                        }
                        max3[j] = *i;
                        break;
                    }
                }               
                
            }            
        }
        else{  //already have three value
            for(size_t j = 0; j < max3.size(); ++j)
            {
                    if(*i == max3[j])
                        break;
                    if(*i > max3[j]) {                      
                        for(size_t k = max3.size() - 1; k > j; k--)
                        {
                            max3[k] = max3[k - 1];
                        }
                        max3[j] = *i;
                        break;
                    }
            }  

        }
    }
    return max3.size() < 3 ? max3[0] : max3[2];
}


int main(){
    vector<int> nums = {1,2,2,5,3,5};
    int result = thirdMax(nums);
    return 0;
}