/*
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

#include <vector>
#include <forward_list>

using namespace std;



//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


// 方法1：空间复杂度o(1)
/*
类似于merge sort的merge()方法
*/
/*
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // merge到l1中
    ListNode* result = new ListNode(0);
    result->next = l1;
    l1 = result;

    while(l1->next && l2){
        if(l2->val < l1->next->val){
            // 插入到l1之前
            ListNode* newNode = new ListNode(l2->val);
            newNode->next = l1->next;
            l1->next = newNode;
            l2 = l2->next;
        }
        l1 = l1->next;      
        
    }
    while(l2){
        ListNode* newNode = new ListNode(l2->val);
        l1->next = newNode;
        l1 = l1->next; 
        l2 = l2->next;
    }

    return result->next;
}
*/

// 更简洁的写法
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2; // 如果l1或l2还有，直接挂在tail的最后
    return dummy.next;
}

int main(){
    vector<int> v1{-9,3};
    vector<int> v2{5,7};

    // 初始化链表l1
    ListNode* header1 = nullptr;
    ListNode* l1 = nullptr; 
    for(size_t i = 0; i < v1.size(); i++)
    {
        if(i == 0){
            l1 = new ListNode(v1[i]);
            header1 = l1;
        }            
        else{
            l1->next = new ListNode(v1[i]);
            l1 = l1->next;
        }        
    }
    // 遍历
    // int num = 0;
    // l1 = header1;
    // while(l1)
    // {
    //     num = l1->val;
    //     l1 = l1->next;
    // }

    // 初始化链表l2
    ListNode* header2 = nullptr;
    ListNode* l2 = nullptr; 
    for(size_t i = 0; i < v2.size(); i++)
    {
        if(i == 0){
            l2 = new ListNode(v2[i]);
            header2 = l2;
        }            
        else{
            l2->next = new ListNode(v2[i]);
            l2 = l2->next;
        }        
    }

    ListNode *result = mergeTwoLists(header1, header2);

    return 0;
}