/**
 * 225. Implement Stack using Queues
 
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

**/

#include <queue>

using namespace std;


/**
 * ����1.ʹ���������С��ռ临�Ӷ�o(n)
 * ����queue1����洢���ݣ�����queue2ֻ����ջҪpop������Ԫ��ʱ�����queue1
 * �ڵ���ʱ����
 */
namespace Stack_method1{
    class MyStack {
    public:
        /** Initialize your data structure here. */
        MyStack() {
            size = 0;
            top_value = NULL;
        }
        
        /** Push element x onto stack. */
        void push(int x) {                
            q1.push(x);
            top_value = x;
            size += 1;
        }
        
        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            if(size <= 0){
                return NULL;
            }
            else{
                // ��q1���һ��Ԫ��ǰ��ȫ��Ԫ��ת�Ƶ�q2,Ȼ��q1��ֻʣ���һ��Ԫ�أ����ӡ��ٽ�q2������ת�ƻ�q1
                if(q1.size() == 1){
                    top_value = NULL;
                    size = 0;
                    int result = q1.front();
                    q1.pop();
                    return result;
                }
                else{
                    while(q1.size() > 1){
                        if(q1.size() == 2)
                            top_value = q1.front();
                        q2.push(q1.front());
                        q1.pop();
                    }  
                    int result = q1.front();                  
                    q1.pop();
                    size -= 1;                    
                    while(q2.size() > 0){
                        q1.push(q2.front());
                        q2.pop();
                    }
                    return result;
                }

            }
            
        }
        
        /** Get the top element. */
        int top() {
            return top_value;
        }
        
        /** Returns whether the stack is empty. */
        bool empty() {
            return size <= 0;
        }
    private:
        queue<int> q1; //�洢����
        queue<int> q2; // �������pop����
        int size;
        int top_value;
    };

    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack obj = new MyStack();
     * obj.push(x);
     * int param_2 = obj.pop();
     * int param_3 = obj.top();
     * bool param_4 = obj.empty();
     */
}

/**
 * ����2.ʹ���������С��ռ临�Ӷ�o(n)
 * ����queue1����洢���ݣ�����queue2ֻ����ջҪpop������Ԫ��ʱ�����queue1
 * �ڲ���ʱ����
 */
namespace Stack_method2{
    class MyStack {
    public:
        /** Initialize your data structure here. */
        MyStack() {
            size = 0;
            top_value = NULL;
        }
        
        /** Push element x onto stack. */
        void push(int x) {     
            if(q1.empty()){
                q1.push(x);
                top_value = x;
                size += 1;
            }
            else{
                while(!q1.empty()){
                    q2.push(q1.front());
                    q1.pop();
                }
                q1.push(x);
                while(!q2.empty()){
                    q1.push(q2.front());
                    q2.pop();
                }

                top_value = q1.front();
                size += 1;
            }
                       
        }
        
        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            int result;
            if(size <= 0){
                return NULL;
            }
            else{
                result = q1.front();
                q1.pop();
                size -= 1;
                if(!q1.empty()){
                    top_value = q1.front();
                }
                else{
                    top_value = NULL;
                }
            }

            return result;
        }
        
        /** Get the top element. */
        int top() {
            return top_value;
        }
        
        /** Returns whether the stack is empty. */
        bool empty() {
            return size <= 0;
        }
    private:
        queue<int> q1; //�洢����
        queue<int> q2; // �������pop����
        int size;
        int top_value;
    };

    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack obj = new MyStack();
     * obj.push(x);
     * int param_2 = obj.pop();
     * int param_3 = obj.top();
     * bool param_4 = obj.empty();
     */
}

/**
 * ����3��ʹ�õ������С�
 * ÿ�β�����ֵʱ������˳�򡣵����ķ���ͨ�����ϵ�pop, push����ԭ����������ֵλ�õ�������ǰ
 * */
namespace Stack_method3{
    class MyStack {
    public:
        /** Initialize your data structure here. */
        MyStack() {
            size = 0;
            top_value = NULL;
        }
        
        /** Push element x onto stack. */
        void push(int x) {     
            if(q1.empty()){
                q1.push(x);
                top_value = x;
                size += 1;
            }
            else{
                q1.push(x);
                int tmp;
                int turn = q1.size() - 1;
                while(turn){
                    tmp = q1.front();
                    q1.pop();
                    q1.push(tmp);
                    turn--;
                }
                top_value = q1.front();
                size += 1;
            }
                       
        }
        
        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            int result;
            if(size <= 0){
                return NULL;
            }
            else{
                result = q1.front();
                q1.pop();
                size -= 1;
                if(!q1.empty()){
                    top_value = q1.front();
                }
                else{
                    top_value = NULL;
                }
            }

            return result;
        }
        
        /** Get the top element. */
        int top() {
            return top_value;
        }
        
        /** Returns whether the stack is empty. */
        bool empty() {
            return size <= 0;
        }
    private:
        queue<int> q1; //�洢����
        queue<int> q2; // �������pop����
        int size;
        int top_value;
    };

    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack obj = new MyStack();
     * obj.push(x);
     * int param_2 = obj.pop();
     * int param_3 = obj.top();
     * bool param_4 = obj.empty();
     */
}