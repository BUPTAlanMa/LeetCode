/*
707. Design Linked List

Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
Note:

All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.
*/

#include <vector>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
private:
  ListNode *head;
  ListNode *last; //末节点，在单向链表中比尾节点有用,方便后插节点
  int count; // 节点数量

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new ListNode(0);
        last = head;
        count = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= count)
            return -1;
        ListNode *tail = head->next;
        while(index--)
            tail = tail->next;
        return tail->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head->next;
        head->next = node;
        
        ++count;
        if(count == 1)
            last = last->next;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        last->next = new ListNode(val);
        last = last->next;
        ++count;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > count)
            return;
        if(index == count)
            return addAtTail(val);

        ListNode *tail = head;
        while(index--)
            tail = tail->next;

        ListNode* node = new ListNode(val);
        node->next = tail->next;
        tail->next = node;
        ++count;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        // the index is valid 
        if(index >= count)
            return;
        ListNode *tail = head;
        while(index--)  tail = tail->next;
        if(!tail->next->next) // 如果删掉的是末节点，需要更新末节点
            last = tail;
        tail->next = tail->next->next;
        --count;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */




int main(){
    vector<int> v1{1,2,3,6,4,5};

    // 初始化链表l1
    MyLinkedList t1 = MyLinkedList();
    
    /*
    ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
    [[],[1],[3],[1,2],[1],[1],[1]]  
    */
    t1.addAtHead(1);
    t1.addAtTail(3);
    t1.addAtIndex(1, 2);
    int o1 = t1.get(1);
    t1.deleteAtIndex(1);
    int o2 = t1.get(1);

    return 0;
}