/*
849. Maximize Distance to Closest Person

In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.
*/

#include <vector>
#include <ctime>
#include <iostream>
#include <limits>
#include <cstdlib>


using namespace std;

// 思路：一次遍历,寻找零区间的起点和终点
int maxDistToClosest(vector<int>& seats) {
    int maxDisc = 0;
    int lo = 0;
    int hi = 0;
    bool start = false;
    int Disc;
    for(size_t i = 0; i < seats.size(); i++)
    {
        if(seats[i] == 0 && !start){
            start = true;
            lo = i;
            hi = lo;
        }
        else{
            if(start && seats[i] == 1){
                start = false;
                hi = i - 1;
                if(lo == 0) Disc = hi - lo + 1;
                else Disc = (hi - lo + 2) / 2;
                maxDisc = max(maxDisc, Disc);
            }
            if(start && seats[i] == 0)
                hi++;
            if(hi == seats.size() - 1){
                Disc = seats.size() - lo;
                maxDisc = max(maxDisc, Disc);
            }         
        }    
                
    }
    return maxDisc;
}

int main(){
    vector<int> Input = {0,0,0,1};
    clock_t start = clock();
    double duriation = 0;

    cout << "result: " << maxDistToClosest(Input) << endl;
    duriation = (clock() - start) / (double)CLOCKS_PER_SEC;

    cout << "time consume(ms): " << duriation << endl;
    return 0;

}