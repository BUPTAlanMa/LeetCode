/*
234. Palindrome Linked List
判断链表是否是回文链表

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include <vector>
#include <stack>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

// 初始化链表，带头节点
ListNode* initListFromVec(vector<int>& nums)
{
    // 初始化链表l1
    ListNode* header = new ListNode(0);
    ListNode* tail = header;
    
    for(size_t i = 0; i < nums.size(); i++)
    {
        ListNode* node = new ListNode(nums[i]);
        tail->next = node;
        tail = tail->next;  
    }
    return header;
}

// 初始化链表，不带头节点
ListNode* initListFromVecUnHeader(vector<int>& nums){
    return initListFromVec(nums)->next;
}

// 方法1：时间复杂度o(n), 空间复杂度o(n)
/*
18.67%
1. 找到链表中点
使用两个指针，一个步长为1，一个步长为2.同时将步长为1遍历的节点入栈
当步长为2的到达尾节点，步长为1的到达中间节点
2. 步长为1的继续遍历，同时不断从栈中弹出元素进行比较，判断是否相等
*/
/*
bool isPalindrome(ListNode* head) {
    if(!head || !head->next)
        return true;
    stack<int> s;
    ListNode *slow = head; // 寻找中间节点middle node
    s.push(slow->val);
    ListNode *fast = head->next;    
    while(fast->next){     
        if(fast->next->next) {  
            fast = fast->next->next;            
            slow = slow->next; 
            s.push(slow->val);
        }
        else{
            slow = slow->next;
            break;
        }
    }
    // 从右半段开始对比
    slow = slow->next; 
    while(slow){
        if(s.empty() || slow->val != s.top())
            return false;
        slow = slow->next;
        s.pop();
    }
    if(!s.empty())
        return false;
    return true;
}
*/

// 方法2：翻转链表, 时间复杂度o(n), 空间复杂度o(1)
/*
98.23%
1. 找中间节点
2. 翻转右半部分链表
3. 对比左半部分和右半部分
*/
ListNode* reverseList(ListNode* head) {
    if(!head)
        return head;
    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *next = nullptr;
    while(current){
        next = current->next; 
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {
    if(!head || !head->next)
        return true;
    // 1. 找中间节点(n / 2)
    ListNode *left_head = head;
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast->next && fast->next->next){        
            slow = slow->next;
            fast = fast->next->next;
    }
    
    slow = slow->next;
    // 2. 翻转右半部分链表
    ListNode *right_head = reverseList(slow);

    // 对比左半部分和右半部分
    while(right_head){
        if(left_head->val != right_head->val)
            return false;
        left_head = left_head->next;
        right_head = right_head->next;
    }
    return true;
}


int main(){
    vector<int> v1{1,4,5,4,2};

    // 初始化链表l1
    ListNode *header1 = initListFromVecUnHeader(v1);
    bool result = isPalindrome(header1);

    return 0;
}
