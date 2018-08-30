/*
Given a non-negative index k where k �� 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

#include <vector>
#include <cstdlib>

using namespace std;


// ����1���ռ临�Ӷ�Ϊ0��ʱ�临�Ӷ�o(n^2),ʱ�临�Ӷ�̫��
/* A(i)[j] = A(i-1)[j] + A(i-1)[j-1]
* ��ֹ������
* j - 1 = 0, ��ʱ����1
* i = j, ��ʱ����1.���ʵ��������һ��Ԫ��
*/ 
/*
int getItem(int rowIndex, int colIndex){
    if(colIndex == 0)
        return 1;
    if(rowIndex == colIndex)
        return 1;

    return getItem(rowIndex - 1, colIndex) + getItem(rowIndex - 1, colIndex - 1);
}

vector<int> getRow(int rowIndex) {
    if(rowIndex < 0)
        return {};
    if(rowIndex == 0){
        return {1};
    }
    vector<int> result(rowIndex + 1);


    result[0] = 1;
    for(size_t i = 1; i <= result.size() / 2; i++)
    {
        result[i] = getItem(rowIndex, i);
    }

    int low = 0;
    int high = result.size() - 1;
    while(low < high){
        result[high--] = result[low++];
    }
    return result;
}
*/

/*
* ����2�� ʹ�ö���ռ�
*/
vector<int> getRow(int rowIndex) {    

    /* ���򣬱�����ĵ�����
    vector<int> result(rowIndex + 1, 1);
    int tmp1;
    int tmp2;
    for(size_t i = 1; i <= rowIndex; i++)
    {   
        tmp1 = result[0];
        for(size_t j = 1; j < i; j++)
        {
            tmp2 = result[j];
            result[j] = tmp1 + tmp2;
            tmp1 = tmp2;
        }                
    }
    */
   
    vector<int> result(rowIndex + 1, 0);
    result[0] = 1;
    // ���򲻻���ָ��ǵ�����
    for(size_t i = 1; i <= rowIndex; i++)
    {   
        for(size_t j = i; j > 0; j--)
        {
            result[j] = result[j] + result[j - 1];
        }                
    }

    return result;
}

int main(){
    vector<int> result = getRow(4);
    system("pause");
    return 0;
}
