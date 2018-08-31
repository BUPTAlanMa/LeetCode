/*
206. Reverse Linked List

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
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

/*
方法1: 使用stack, 时间复杂度0(n),空间复杂度o(n)
*/
/*
ListNode* reverseList(ListNode* head) {
    if(!head)
        return head;
    stack<ListNode *> s;
    while(head){
        s.push(head);
        head = head->next;
    }

    ListNode* result = s.top();
    ListNode *tail = result;
    s.pop();
    while(!s.empty()){
        tail->next = s.top();
        tail = tail->next;
        s.pop();
    }
    tail->next = nullptr;

    return result;
}
*/

/*
方法2: 不使用stack, 时间复杂度0(n),空间复杂度o(1)
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

int main(){
    vector<int> v1{1,2,3,4,5};

    // 初始化链表l1
    ListNode *header1 = initListFromVecUnHeader(v1);
    ListNode *result = reverseList(header1);

    return 0;
}