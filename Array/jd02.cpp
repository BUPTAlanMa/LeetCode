#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    int N, M;
    cin >> N;
    cin >> M;
    vector<int> input(M *2);    
    for(int i = 0; i < M *2; i+=2)
    {
        cin >> input[i];
        cin >> input[i + 1];
    }
        // 思路，先按照使得任意两个同一集合内的点之间没有边相连，拆分集合
    // 然后检查条件2 使得任意两个同一集合内的点之间没有边相连
    // 初始化存储
    vector<vector<int>> sets;
    sets.push_back(vector<int>(N));
    for(int i = 1; i < N; i++)
    {
        sets[0][i - 1] = i;
    }
    
    for(int i = 0; i < M *2; i+=2)
    {
        int num1 = input[i];
        int num2 = input[i];
        // 遍历每一个集合，如果发现同时存在，删掉后一个(该位置赋值-1)，将之放入下一个集合
        // 下一个集合也这么操作，如果没有下一个，新建一个新集合放入
        bool needInsert = false;
        int insert_val;
        for(int s = 0; s < sets.size(); s++)
        {
            if(needInsert){
                if()
            }
            if((find(sets[s].begin(), sets[s].end(), num1) != sets[s].end()) && (find(sets[s].begin(), sets[s].end(), num2) != sets[s].end())){
                if(s == sets.size() - 1){
                    sets.push_back({num2});
                    sets[s][num2 - 1] = -1;
                }
                else{
                    needInsert = true;
                    insert_val = num2;
                    sets[s][num2 - 1] = -1;
                }
            }
        }
        
    }
       



    
}