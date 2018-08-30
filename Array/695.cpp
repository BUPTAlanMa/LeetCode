/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/

#include <vector>
#include <set>
#include <iostream>
#include <iterator>

using namespace std;
// ˼·�����ǵ����ķ���ȥѰ��ĳ����ȫ���ĵ�
struct Point{   
    Point(int r, int c) : _r(r), _c(c) { };
    bool operator<(const Point& pt) const {
        return (_r < pt._r) && (_c < pt._c);
    };

    friend ostream& operator<<(ostream& os, const Point& pt); 
    
    int _r;
    int _c;
};

ostream& operator<< (ostream& os, const Point& pt) {
    os << " Point.Row: " << pt._r << " , Point.Column: " << pt._c;
    return os;
}


void searchRegin(Point& pt, vector<vector<int>>& grid, vector<Point>& regionPoint, vector<vector<int>>& isChecked, int rows, int columns){
    
    // ��ptΪ���ģ���Ѱ������������ڷ��������ĵ㣬�����regionPoint
    // up
    if(pt._r - 1 >= 0 && !isChecked[pt._r - 1][pt._c]){
        // �ںϷ���Χ�ڣ���δ������        
        if(grid[pt._r - 1][pt._c] == 1){ // Ԫ��ֵΪ1����ͨ
            Point up(pt._r - 1, pt._c);
            regionPoint.push_back(up);

            isChecked[up._r][up._c] = true; //isCheckedֻ���ֵΪ1��Ԫ��  
            searchRegin(up, grid, regionPoint, isChecked, rows, columns); 
                     
        }       
        
    }
    // down
    if(pt._r + 1 < rows && !isChecked[pt._r + 1][pt._c]){
        // �ںϷ���Χ�ڣ���δ������        
        if(grid[pt._r + 1][pt._c] == 1){
            Point down(pt._r + 1, pt._c);
            regionPoint.push_back(down);

            isChecked[down._r][down._c] = true; //isCheckedֻ���ֵΪ1��Ԫ��
            searchRegin(down, grid, regionPoint, isChecked, rows, columns);
            
        }   
    }
    // left
    if(pt._c - 1 >= 0 && !isChecked[pt._r][pt._c - 1]){
        // �ںϷ���Χ�ڣ���δ������        
        if(grid[pt._r][pt._c - 1] == 1){
            Point left(pt._r, pt._c - 1);
            regionPoint.push_back(left);
            isChecked[left._r][left._c] = true; //isCheckedֻ���ֵΪ1��Ԫ��
            searchRegin(left, grid, regionPoint, isChecked, rows, columns);
        }    
    }
    //right
    if(pt._c + 1 < columns && !isChecked[pt._r][pt._c + 1]){
        // �ںϷ���Χ�ڣ���δ������        
        if(grid[pt._r][pt._c + 1] == 1){
            Point right(pt._r, pt._c + 1);
            regionPoint.push_back(right);
            isChecked[right._r][right._c] = true; //isCheckedֻ���ֵΪ1��Ԫ��
            searchRegin(right, grid, regionPoint, isChecked, rows, columns);         
        }        
    }

    return;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows = grid.size();
    int columns = grid[0].size();
    vector<vector<int>> isChecked(rows, vector<int>(columns));



    int maxArea = 0;
    
    for (int i = 0; i < rows; i++) {        
        for(int j = 0; j < columns; j++) {
            // ��ʵ�ϣ�ֻ�����ֵΪ1��Ԫ�أ����ɵõ�ȫ����
            if(grid[i][j] == 1 && !isChecked[i][j]){                
                vector<Point> regionPoint;
                Point curr(i, j);
                regionPoint.push_back(curr);
                isChecked[i][j] = true; //isCheckedֻ���ֵΪ1��Ԫ��
                cout << "�� " << curr << " ����������" << endl;
                searchRegin(curr, grid, regionPoint, isChecked, rows, columns);
                copy(regionPoint.cbegin(), regionPoint.cend(), ostream_iterator<Point>(cout, " "));
                int searchRegin_area = regionPoint.size();
                cout << endl << "���������� ���Ϊ��" << searchRegin_area << endl;
                if(searchRegin_area > maxArea)
                    maxArea = searchRegin_area;
            }  
        }
    }        

    return maxArea;

}

int main(){
    // vector<vector<int>> grid = {{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    //                              { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
    //                              { 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    //                              { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 },
    //                              { 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
    //                              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
    //                              { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
    //                              { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 }};

    vector<vector<int>> grid = {{0, 1},
                                {1, 1}};
    cout << maxAreaOfIsland(grid);

    return 0;
    // ����
    // Point p1(1, 2);
    // set<Point> regionPoint;
    // regionPoint.insert(p1);
    // regionPoint.insert(p1);
    // copy(regionPoint.cbegin(), regionPoint.cend(), ostream_iterator<Point>(cout, " "));
    // cout << endl;
}