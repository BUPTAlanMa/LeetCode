/*
160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
*/

#include <vector>
#include <limits>
#include <unordered_set>
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


// 方法1：暴力搜索
/*
超时
*/
/*
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *tail;
    while(headA){
        tail = headB;
        while(tail) {
            if(tail == headA)
                return tail;
        }
        headA = headA->next;
    }
    return nullptr;
}
*/

// 方法2：hashTable
/*
7%
空间复杂度o(n)
*/
/*
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> record;
    while(headA) {
        record.insert(headA);
        headA = headA->next;
    }
    while(headB){
        if(record.count(headB)) {
            return headB;
        }
        headB = headB->next;
    }
    return nullptr;
}
*/

// 方法4：利用的是，如果链表相交，它们拥有共同的尾部。所以较长的链表先移位abs(L1-L2)个节点
/*
遍历链表1，记下链表1的长度L1
遍历链表2，记下链表1的长度L2
标记较长的链表，先让较长的链表开始遍历abs(L1-L2)个节点。
此时，两个链表同步遍历，观察是否有节点地址相同
比较两个节点的地址是否相同, 只能判断是否相交，但是不能返回相交的起始节点
时间复杂度o(m+n), 空间复杂度o(1)
*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA && headB)
        return nullptr;
    int len1 = 0;
    ListNode *tail = headA;
    while(tail) {
        len1 += 1;
        tail = tail->next;
    }
    int len2 = 0;
    tail = headB;
    while(tail){
        len2 += 1;
        tail = tail->next;
    }
    bool isList1longer = len1 > len2;
    int diff = isList1longer ? len1 - len2 : len2 - len1;
    if(isList1longer && diff){
        headA = headA->next;
        diff--;
    }
    else{
        headB = headB->next;
        diff--;
    }

    while(headA && headB){
        if(headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return nullptr;
}


// 方法4：只能判断是否相交，但是不能返回相交的起始节点
/*
遍历链表1，记录下最后一个节点的地址
遍历链表2，记录下最后一个节点的地址
比较两个节点的地址是否相同, 只能判断是否相交，但是不能返回相交的起始节点
时间复杂度o(m+n), 空间复杂度o(1)
*/
bool isIntersectionNode(ListNode *headA, ListNode *headB) {
    while(headA && headA->next) {
        headA = headA->next;
    }
    while(headB && headB->next){
        headB = headB->next;
    }
    return headA == headB;
}




int main(){
    vector<int> v1{1,1,2,3,3};
    vector<int> v2{5,7};

    // 初始化链表l1
    ListNode *header1 = initListFromVecUnHeader(v1);

    return 0;
}