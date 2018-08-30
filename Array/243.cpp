/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = ��coding��, word2 = ��practice��, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

// ˼·1�������ֵ䡣��ֵΪ���ʣ� ֵΪ���ֵ����������ǵ��ظ���ֵӦ��Ϊvector���ͣ���
// ���ݸ������������ʣ��ҵ���Ӧ��ֵ�������ֵ�����С���루ѭ�������Сֵ��
int shortestDistance_v1(vector<string>& words, string word1, string word2) {
    return 0;
}

// ˼·2�����ý����ֵ䡣ֱ�Ӳ��Ҹ������������ʵ�λ�ã�����ڶ�Ӧ������vector�С�������С����ͬ����1.
int shortestDistance_v2(vector<string>& words, string word1, string word2) {
    vector<int> word1_pos;
    vector<int> word2_pos;

    for (size_t i = 0; i < words.size(); i++) {
        if(words[i] == word1){
            word1_pos.push_back(i);
        }
        if(words[i] == word2){
            word2_pos.push_back(i);
        }
    }
    int minDistance = words.size();
    for (size_t i = 0; i < word1_pos.size(); i++){
        for(size_t j = 0; j < word2_pos.size(); j++){
            int distance = abs(word1_pos[i] - word2_pos[j]);           
            if(distance < minDistance)
                minDistance = distance;
        }
    }

    return minDistance;
}
// ����3, ����Ч
int shortestDistance_v3(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1, res = INT_MAX;
        for (size_t i = 0; i < words.size(); ++i) {
            if (words[i] == word1) p1 = i;
            else if (words[i] == word2) p2 = i;
            if (p1 != -1 && p2 != -1) res = min(res, abs(p1 - p2));
        }
        return res;
}

int main() {

    return 0;
}