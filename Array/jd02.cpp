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
        // ˼·���Ȱ���ʹ����������ͬһ�����ڵĵ�֮��û�б���������ּ���
    // Ȼ��������2 ʹ����������ͬһ�����ڵĵ�֮��û�б�����
    // ��ʼ���洢
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
        // ����ÿһ�����ϣ��������ͬʱ���ڣ�ɾ����һ��(��λ�ø�ֵ-1)����֮������һ������
        // ��һ������Ҳ��ô���������û����һ�����½�һ���¼��Ϸ���
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