/*
234. Palindrome Linked List
�ж������Ƿ��ǻ�������

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
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

// ����1��ʱ�临�Ӷ�o(n), �ռ临�Ӷ�o(n)
/*
18.67%
1. �ҵ������е�
ʹ������ָ�룬һ������Ϊ1��һ������Ϊ2.ͬʱ������Ϊ1�����Ľڵ���ջ
������Ϊ2�ĵ���β�ڵ㣬����Ϊ1�ĵ����м�ڵ�
2. ����Ϊ1�ļ���������ͬʱ���ϴ�ջ�е���Ԫ�ؽ��бȽϣ��ж��Ƿ����
*/
/*
bool isPalindrome(ListNode* head) {
    if(!head || !head->next)
        return true;
    stack<int> s;
    ListNode *slow = head; // Ѱ���м�ڵ�middle node
    s.push(slow->val);
    ListNode *fast = head->next;    
    while(fast->next){     
        if(fast->next->next) {  
            fast = fast->next->next;            
            slow = slow->next; 
            s.push(slow->val);
        }
        else{
            slow = slow->next;
            break;
        }
    }
    // ���Ұ�ο�ʼ�Ա�
    slow = slow->next; 
    while(slow){
        if(s.empty() || slow->val != s.top())
            return false;
        slow = slow->next;
        s.pop();
    }
    if(!s.empty())
        return false;
    return true;
}
*/

// ����2����ת����, ʱ�临�Ӷ�o(n), �ռ临�Ӷ�o(1)
/*
98.23%
1. ���м�ڵ�
2. ��ת�Ұ벿������
3. �Ա���벿�ֺ��Ұ벿��
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

bool isPalindrome(ListNode* head) {
    if(!head || !head->next)
        return true;
    // 1. ���м�ڵ�(n / 2)
    ListNode *left_head = head;
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast->next && fast->next->next){        
            slow = slow->next;
            fast = fast->next->next;
    }
    
    slow = slow->next;
    // 2. ��ת�Ұ벿������
    ListNode *right_head = reverseList(slow);

    // �Ա���벿�ֺ��Ұ벿��
    while(right_head){
        if(left_head->val != right_head->val)
            return false;
        left_head = left_head->next;
        right_head = right_head->next;
    }
    return true;
}


int main(){
    vector<int> v1{1,4,5,4,2};

    // ��ʼ������l1
    ListNode *header1 = initListFromVecUnHeader(v1);
    bool result = isPalindrome(header1);

    return 0;
}
