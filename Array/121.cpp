/*
121. Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/


#include <vector>
#include <limits.h>
#include <ctime>
#include <iostream>

using namespace std;
/* 过于复杂......................
// 思路：找到全部极小值和极大值。然后，确定差值最大的极小值和极大值对（极小值索引小于极大值索引）。
// 遵循及早买入和及早卖出的原则，定义极小极大值
// 极小值允许等于右边。极大值允许等于右边
int maxProfit(vector<int>& prices) {
    vector<int> minIndex;
    vector<int> maxIndex;

    for (size_t i = 0; i < prices.size(); i++){
        if(i == 0){
            // 起始位置只考虑极小值
            if(prices[i] < prices[i + 1])
                minIndex.push_back(i);
            // if(prices[i] > prices[i + 1])
            //     maxIndex.push_back(i);
        }
        // 终止位置只考虑极大值
        if(i == prices.size() - 1){
            if(prices[i] > prices[i - 1])
                maxIndex.push_back(i);
        }
        
        if(prices[i] < prices[i - 1] && prices[i] <= prices[i + 1])
            minIndex.push_back(i);
        
        if(prices[i] > prices[i - 1] && prices[i] >= prices[i + 1])
            maxIndex.push_back(i);
    }


    int result = 0;
    int currMaxValue = 0;
    if(minIndex.size() == 0){
        if(maxIndex.size() == 0)
            // 水平
            return 0;
        else
        {
            //单调递增
            return prices[prices.size() - 1] - prices[0];
        }        
    }
    if(minIndex.size() == 0){

    for (size_t i = 0; i < minIndex.size(); i++){
        for (size_t j = 0; j < maxIndex.size(); j++){
            if(j > i){
                currMaxValue = prices[maxIndex[j]] - prices[minIndex[i]];
                if(currMaxValue > result)
                    result = currMaxValue;
            }
        }
    }

    return result;
}
*/
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxprofit = 0;
    for(size_t i = 0; i < prices.size(); i++)
    {
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
        else if(prices[i] - minPrice > maxprofit){
            maxprofit = prices[i] - minPrice;
        }

    }

    return maxprofit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    clock_t start;
    double duration;
    start = clock();

    cout << "result: " << maxProfit(prices) << endl;

    clock_t end = clock();
    duration = (end - start) / (double) CLOCKS_PER_SEC; //ms

    cout<<"time consume(ms): "<< duration <<'\n';
    return 0;
}