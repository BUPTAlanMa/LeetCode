/*
830. Positions of Large Groups

In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.

 

Example 1:

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
*/
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> result;
    auto curr = S[0]; //当前字符, const char*
    int curr_first = 0;
    int curr_num = 0; //当前字符连续个数
    for (size_t i = 0; i < S.size(); i++){
        if(S[i] == curr){
            curr_num += 1;
        }
        if(S[i] != curr || i == S.size() - 1) {//末尾处理
            if(curr_num >= 3){
                result.push_back({curr_first, curr_first + curr_num - 1});
            }
            if(i == S.size() - 1)
                break;
            curr_first = i;
            curr = S[i];
            curr_num = 1;
        }

    }

    return result;
}

int main() {
    string s = "aaa";
    largeGroupPositions(s);
    return 0;
}