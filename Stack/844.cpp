/*
844. Backspace String Compare

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

#include <stack>
#include <string>
using namespace std;

/**
 * 方法1：利用stack, 空间复杂度o(N+M),时间复杂度o(N+M)
*/
/*
bool backspaceCompare(string S, string T) {
    bool result = false;
    stack<char> s;
    stack<char> t;
    for(char c : S){
        if(c == '#'){
            if(s.size() > 0)
                s.pop();
        }
        else{
            s.push(c);
        }
    }

    for(char c : T){
        if(c == '#'){
            if(t.size() > 0)
                t.pop();
        }
        else{
            t.push(c);
        }
    }

    if(s.size() != t.size())
        return false;
    while(!s.empty() && !t.empty() && s.top() == t.top()){
        s.pop();
        t.pop();
    }
    if(s.empty() && t.empty())
        return true;
    return result;
}
*/
/**
 * 方法2：不利用栈，反向遍历。反向遍历的结果就是最终的字符串输入结果的逆序
 * 时间复杂度o(N+M),空间复杂度o(1)
*/
bool backspaceCompare(string S, string T) {
    int s_index = S.size() - 1;
    int t_index = T.size() - 1;
    int s_delete_num = 0;
    int t_delete_num = 0;
    while(s_index >= 0 || t_index >= 0){
        // 处理内部的#
        while(s_index >= 0){
            if(S[s_index] == '#'){
                s_delete_num += 1;
                s_index--;
            }                
            else if(s_delete_num > 0){
                s_delete_num -= 1;
                s_index--;
            }
            else
                break;
        }

        while(t_index >= 0){
            if(T[t_index] == '#'){
                t_delete_num += 1;
                t_index--;
            }                
            else if(t_delete_num > 0){
                t_delete_num -= 1;
                t_index--;
            }
            else
                break;
        }
        if(s_index >= 0 && t_index >= 0 && S[s_index] != T[t_index])
            return false;
        if((s_index < 0) != (t_index < 0))
            return false;
            
         s_index--;
         t_index--;
    }

    return true;
}



int main(){
    string S = "ab#c";
    string T = "ad#c";
    bool result = backspaceCompare(S, T);
    return 0;
}