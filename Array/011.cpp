/*
11. Container With Most Water

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
**/

#include <vector>
#include <cmath>
using namespace std;

/**
 * 方法1：两个指针，一个从左到右遍历，一个从右到左遍历
 * 每次指向较小值的指针进行位置更新
 */ 
int maxArea(vector<int>& height) {
    if(height.size() < 3)
        return 0;
    int lo = 0;
    int hi = height.size() - 1;
    int area = min(height[lo], height[hi]) * (hi - lo);
    int lo_val = height[lo];
    int hi_val = height[hi];
    int new_area;
    while(lo < hi){         

        new_area = min(height[lo], height[hi]) * (hi - lo);
        if(new_area > area)
            area = new_area;

        if(height[lo] > height[hi]){
            // 找到下一个大于该较小值的索引
            int curr = height[hi];
            while(lo < hi &&  height[hi] <= curr)
                hi--;
        }
        else{
            int curr = height[lo];
            while(lo  < hi &&  height[lo] <= curr)
                lo++;
        }

    }

    return area;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = maxArea(height);
    return 0;
}