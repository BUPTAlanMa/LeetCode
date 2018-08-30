/*
203. Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

#include <vector>
#include <limits>
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
ListNode* removeElements(ListNode* head, int val) {
    ListNode header(0);
    ListNode *tail = &header;
    tail->next = head;
    while(tail->next){
        if(tail->next->val == val){
            tail->next = tail->next->next;
        }
        else
            tail = tail->next;
    }
    return header.next;
}
*/

// 更快
ListNode* removeElements(ListNode* head, int val) {
    ListNode *pseudo_head = new ListNode(0);
    pseudo_head->next = head;
    ListNode *cur = pseudo_head;
    while(cur){
        if(cur->next && cur->next->val == val)   cur->next = cur->next->next;
        else    cur = cur->next;
    }
    return pseudo_head->next;
}

int main(){
    vector<int> v1{1,2,6,3,4,5,6};
    vector<int> v2{5,7};

    // 初始化链表l1
    ListNode *header1 = initListFromVecUnHeader(v1);

    ListNode *result = removeElements(header1, 6);

    return 0;
}