/*
 232. Implement Queue using Stacks

 Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 */
 

#include <stack>

using namespace std;

/**
 * 方法1：两个栈
 * 入队时调整
*/
namespace MyQueue_m1{
    class MyQueue {
    public:
        /** Initialize your data structure here. */
        MyQueue() {
            
        }
        
        /** Push element x to the back of queue. */
        void push(int x) {
            if(s1.empty())
                s1.push(x);
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                s1.push(x);
                while(!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();
                }
            }
        }
        
        /** Removes the element from in front of queue and returns that element. */
        int pop() {
            if(s1.empty())
                return NULL;
            else{
                int result = s1.top();
                s1.pop();
                return result;
            }
            
        }
        
        /** Get the front element. */
        int peek() {
            if(s1.empty())
                return NULL;
            else{
                return s1.top();
            }
        }
        
        /** Returns whether the queue is empty. */
        bool empty() {
            return s1.empty();
        }
    private:
        stack<int> s1;
        stack<int> s2;
    };

    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue obj = new MyQueue();
     * obj.push(x);
     * int param_2 = obj.pop();
     * int param_3 = obj.peek();
     * bool param_4 = obj.empty();
     */
}

/**
 * 方法1：两个栈
 * 出队时调整
*/
namespace MyQueue_m2{
    class MyQueue {
    public:
        /** Initialize your data structure here. */
        MyQueue() {
            top_value = NULL;
        }
        
        /** Push element x to the back of queue. */
        void push(int x) {
            if(s1.empty()){
                top_value = x;
            }
            s1.push(x);
        }
        
        /** Removes the element from in front of queue and returns that element. */
        int pop() {
            if(s1.empty())
                return NULL;
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                int result = s2.top();
                s2.pop();
                if(!s2.empty()){
                    top_value = s2.top();
                    while(!s2.empty()){
                        s1.push(s2.top());
                        s2.pop();
                    }
                }
                else
                    top_value = NULL;
                
                return result;
            }
            
        }
        
        /** Get the front element. */
        int peek() {
            return top_value;
        }
        
        /** Returns whether the queue is empty. */
        bool empty() {
            return s1.empty();
        }
    private:
        stack<int> s1;
        stack<int> s2;
        int top_value;
    };

    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue obj = new MyQueue();
     * obj.push(x);
     * int param_2 = obj.pop();
     * int param_3 = obj.peek();
     * bool param_4 = obj.empty();
     */
}

int main(){
    return 0;
}
