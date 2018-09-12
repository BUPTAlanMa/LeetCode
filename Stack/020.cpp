/*
20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include <stack>
#include <string>

using namespace std;

/**
 * 方法：遇见指定字符的左半部分，将其右半部分入栈。反之，栈顶元素出栈并与之比较
 * 一旦未遍历结束，但栈空，则说明右半部分多于左半部分
 * 遍历结束，但栈不为空，则说明左半部分多于右半部分
 * */
bool isValid(string s) {
    if(s.size() % 2 != 0)  // 提前退出
        return false;
    stack<char> chars;
    bool result = true;
    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[i]=='{' || s[i] == '(' || s[i]=='['){
            if(s[i]=='{')
                chars.push('}');
            else if(s[i]=='(')
                chars.push(')');
            else
                chars.push(']');
        }
        else if (s[i]=='}' || s[i] == ')' || s[i]==']') {
            if(chars.empty())
                return false;
            char tmp = chars.top();
            chars.pop();                
            if (tmp != s[i])
                return false;                
        }
        else return false;
    }
    if(!chars.empty())
        return false;

    return result;

}

int main(){
    string s = "()[]}}";
    bool result = isValid(s);
    return 0;
}