#include <vector>
#include <cstdio>
#include <iostream>
#include <stdexcept>
using namespace std;

int main(){
    int N;
    cin >> N;
    // 初始化存储
    vector<vector<int> > nums(N);    
    for(int i = 0; i < N; i++)
    {
        nums[i] = vector<int>(3);
        cin >> nums[i][0];
        cin >> nums[i][1];
        cin >> nums[i][2];
        cin.clear();
    }
    int result = 0;
    // 两层遍历    
    for(int i = 0; i < N - 1; i++)
    {        
        for(int j = i + 1; j < N; j++)
        {
            if(nums[i][0] < nums[j][0] && nums[i][1] < nums[j][1] && nums[i][2] < nums[j][2])
                result += 1;
        }        
    }

    cout << result;
}