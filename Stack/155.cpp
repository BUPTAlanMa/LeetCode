/*
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include <climits>
#include <vector>
#include <stdexcept>

using namespace std;

// 54.28%
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        vector<int> data;
        min_val = INT_MAX;
        
        size = 0;
        top_index = size - 1;
    }
    
    void push(int x) {
        if(size == 0)
            min_val = x;
        else{
            if(x < min_val)
                min_val = x;
        }
        ++top_index;
        ++size;
        if(top_index == size-1){
            data.push_back(x);
        }
        data[top_index] = x;
    }
    
    void pop() {
        if(top_index < 0)
            throw out_of_range("Stack is empty..");
        int val = data[top_index];
        --top_index;
        --size;
        if(val == min_val){ // 更新最小值
            min_val = data[top_index];
            for(int i = top_index - 1; i >= 0; i--)
            {
                if(data[i] < min_val)
                    min_val = data[i];
            }
            
        }
    }

    int top() {
        if(top_index < 0)
            throw out_of_range("Stack is empty..");
        return data[top_index];
    }
    
    int getMin() {
        return min_val;
    }

private:
    vector<int> data;
    int min_val;
    size_t size;
    size_t top_index; //指示栈顶元素位置
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(){
    // ["MinStack","push","push","push","getMin","pop","top","getMin"]
    // [[],[-2],[0],[-3],[],[],[],[]]
    MinStack ms = MinStack();
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    int r1 = ms.getMin();
    ms.pop();
    ms.pop();
    int r2 = ms.getMin();
    return 0;
}