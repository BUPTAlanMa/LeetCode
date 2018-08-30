/*
83. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* header = new ListNode(0);
    ListNode *tail = header;
    while(head){
        if(tail == header || tail->val != head->val){
            tail->next = new ListNode(head->val);
            tail = tail->next;
        }
        head = head->next;
    }
    return header->next;
}
*/
// 优化
/*
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* header = new ListNode(0);
    ListNode *tail = header;
    while(head){
        if(tail == header || tail->val != head->val){
            tail->next = head;
            tail = tail->next;
        }
        head = head->next;
    }
    tail->next = nullptr;
    return header->next;
}
*/

// 方法2：
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;
    while(cur) {
        while(cur->next && cur->val == cur->next->val) {
            cur->next = cur->next->next;
        }
        cur = cur->next;
    }
    return head;
}


int main(){
    vector<int> v1{1,1,2,3,3};
    vector<int> v2{5,7};

    // 初始化链表l1
    ListNode *header1 = initListFromVecUnHeader(v1);

    ListNode *result = deleteDuplicates(header1);

    return 0;
}
