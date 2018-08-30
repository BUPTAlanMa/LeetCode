/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/
/*
这里假定的是nums元素不重复。所以可以使用map。
*/
#include <vector>
#include <map>
#include <algorithm> 
#include <iterator>
#include <iostream>
#include <string>

using namespace std;


std::vector<int> twoSum(std::vector<int> &nums, int target){
    // 存放结果
    std::vector<int> result;
    std::map<int, int> mapping;    

    for (size_t i = 0; i < nums.size(); i++)
    {
        int sub = target - nums[i];
        if (mapping.find(sub) != mapping.end()) {
            result.push_back(i);
            result.push_back(mapping[sub]);
            break;
        }
        else {
            mapping[nums[i]] = i;
        }
    }

    return result;

};

int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);
    // 逐元素打印，空格分离
    if(result.size() > 0){
        cout << "Find at index..." << endl;
        copy(result.cbegin(), result.cend(), ostream_iterator<int>(cout, " "));
    }
    else {
        cout << "Not Found..." << endl;
    }    
    cout << endl;

    return 0;
}

