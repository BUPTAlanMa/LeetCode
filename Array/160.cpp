/*
160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 �� a2
                   �K
                     c1 �� c2 �� c3
                   �J            
B:     b1 �� b2 �� b3
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

// ��ʼ��������ͷ�ڵ�
ListNode* initListFromVec(vector<int>& nums)
{
    // ��ʼ������l1
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

// ��ʼ����������ͷ�ڵ�
ListNode* initListFromVecUnHeader(vector<int>& nums){
    return initListFromVec(nums)->next;
}


// ����1����������
/*
��ʱ
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

// ����2��hashTable
/*
7%
�ռ临�Ӷ�o(n)
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

// ����4�����õ��ǣ���������ཻ������ӵ�й�ͬ��β�������Խϳ�����������λabs(L1-L2)���ڵ�
/*
��������1����������1�ĳ���L1
��������2����������1�ĳ���L2
��ǽϳ����������ýϳ�������ʼ����abs(L1-L2)���ڵ㡣
��ʱ����������ͬ���������۲��Ƿ��нڵ��ַ��ͬ
�Ƚ������ڵ�ĵ�ַ�Ƿ���ͬ, ֻ���ж��Ƿ��ཻ�����ǲ��ܷ����ཻ����ʼ�ڵ�
ʱ�临�Ӷ�o(m+n), �ռ临�Ӷ�o(1)
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


// ����4��ֻ���ж��Ƿ��ཻ�����ǲ��ܷ����ཻ����ʼ�ڵ�
/*
��������1����¼�����һ���ڵ�ĵ�ַ
��������2����¼�����һ���ڵ�ĵ�ַ
�Ƚ������ڵ�ĵ�ַ�Ƿ���ͬ, ֻ���ж��Ƿ��ཻ�����ǲ��ܷ����ཻ����ʼ�ڵ�
ʱ�临�Ӷ�o(m+n), �ռ临�Ӷ�o(1)
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

    // ��ʼ������l1
    ListNode *header1 = initListFromVecUnHeader(v1);

    return 0;
}