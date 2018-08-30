/*
141. Linked List Cycle

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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

bool hasCycle(ListNode *head) {
    if(!head) return false;
    ListNode *fast = head; // 步长为1
    ListNode *slow = head->next; // 步长为2
    while(fast && slow && fast->next && slow->next && slow->next->next){
        if(fast != slow){
            fast = fast->next;  
            slow = slow->next->next;
        }
        else
            return true;
    }
    return false;
}


int main(){
    vector<int> v1{1,2};
    hasCycle(initListFromVecUnHeader(v1));
    return 0;
}
