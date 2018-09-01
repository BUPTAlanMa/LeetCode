/*
876. Middle of the Linked List

Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Note:

The number of nodes in the given list will be between 1 and 100.
*/


#include <vector>

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

ListNode* middleNode(ListNode* head) {
    if(!head)
        return head;

    ListNode *fast = head;
    ListNode *slow = head;

    while(fast->next){
        if(fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        else{
            slow = slow->next;
            return slow;
        }
        
    }
    return slow;
}


int main(){
    vector<int> v1{1,2,3,6,4,5};

    // 初始化链表l1
    ListNode *header1 = initListFromVecUnHeader(v1);
    ListNode * result = middleNode(header1);

    return 0;
}