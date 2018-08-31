/*
237. Delete Node in a Linked List

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9], which looks like following:

    4 -> 5 -> 1 -> 9
Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list
             should become 4 -> 1 -> 9 after calling your function.
Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list
             should become 4 -> 5 -> 9 after calling your function.
Note:

The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the linked list.
Do not return anything from your function.
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

/*
void deleteNode(ListNode* node) {
    *node = *node->next;
}
*/ 

// 这里给出列表删除给定节点或给定值的方法
/*
ListNode*  deleteNode(ListNode* header, int index) {
    if(!header)
        return header;

    ListNode dummy(-1);
    dummy.next = header;
    ListNode *tail = &dummy;

    int current = 0;
    while(tail->next){
        if(current == index){
            tail->next = tail->next->next;
        }
        current += 1;
        tail = tail->next;
    }

    return dummy.next;
}
*/

ListNode* deleteNode(ListNode* header, int value) {
    if(!header)
        return header;

    ListNode dummy(-1);
    dummy.next = header;
    ListNode *tail = &dummy;

    while(tail->next){
        if(tail->next->val == value){
            tail->next = tail->next->next;
        }
        tail = tail->next;
    }
    return dummy.next;
}


int main(){
    vector<int> v1{1,2,3,4,5};

    // 初始化链表l1
    ListNode *header1 = initListFromVecUnHeader(v1);
    bool result = deleteNode(header1, 3);

    return 0;
}