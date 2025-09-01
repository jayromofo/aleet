#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>

using namespace std;

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        
    }
};


int main(){
    Solution s;

    vector<vector<int>> t1 = {{2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    vector<vector<int>> t2 = {{2,2,2,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    vector<vector<int>> t3 = {{1,2,2,2,2},{2,2,2,2,0},{2,0,0,0,0},{0,0,2,2,2},{2,0,0,2,0}};
    vector<vector<int>> t4 = {{1}};


    s.lenOfVDiagonal(t1);
    s.lenOfVDiagonal(t2);
    s.lenOfVDiagonal(t3);
    s.lenOfVDiagonal(t4);

    return 0;
}