/*
122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

// 思路，在极小值买入，在极大值卖出
// 极小值是该值小于左右两边，极大值是该值大于左右两边。
// 极小值允许包含等于左侧的情况，但不包含等于右侧
// 极大值允许包含等于右侧的情况，但不包含等于左侧
int maxProfit(vector<int>& prices) {
    if(prices.size() < 2) //不可能进行买入和卖出操作
        return 0;
    int max = 0; // 不买，不卖
    bool isHold = false; // 指示已经买入，持有。
    for (size_t i = 0; i < prices.size(); i++){
        if(i > 0 && i < prices.size() - 1){ 
            if(prices[i] < prices[i + 1] && prices[i] <= prices[i - 1] && !isHold){
                // 买入
                max -= prices[i];
                isHold = true;
            }
            if(prices[i] >= prices[i + 1] && prices[i] > prices[i - 1] && isHold){
                max += prices[i];
                isHold = false;

                // 如果右面剩余元素数量小于2，不可能进行买入卖出，直接跳出
                if(i >= prices.size() - 2)
                    return max;
            }
        }
        else{   
            if(i == prices.size() - 1 && isHold) { // 此时，因为已经买入，所以无论如何都要卖出。当然，这种情况不会发生。
                // 只是处理极端输入
                // 卖出
                max += prices[i];
                isHold = false;
            }        
            //此时，只考虑开始是极小值。因为开始必须先买入
            if(i == 0 && prices[i] < prices[i + 1]){
                // 买入
                max -= prices[i];
                isHold = true;
            }
        }
    }

    return max;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int profit = maxProfit(prices);
    cout << profit << endl;
    return 0;
}