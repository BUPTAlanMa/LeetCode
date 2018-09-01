/*
346. Moving Average from Data Stream

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

*/

#include <queue>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): len(size), sum(0) {
    }
    
    double next(int val) {
        sum += val;
        que.push(val);
        if(que.size() > len)
        {
            sum -= que.front();
            que.pop();
        }
        return sum/que.size();
    }
private:
    int len;    // window size
    double sum; // window size sum
    queue<int> que;
};
 
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
