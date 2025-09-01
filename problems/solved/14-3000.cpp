#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>
#include <cmath>

using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int result = 0;
        int length = 0;
        int width = 0;
        float largest = 0;
        int ls, ws = 0;
        float area = 0;

        for(uint16_t i = 0; i < dimensions.size(); i++){            
            length = dimensions[i][0];
            width = dimensions[i][1];

            ls = length * length;
            ws = width * width;

            area = sqrtf64(ls + ws);
            printf("Index: %d\n", i);
            printf("01A: L: %d  W: %d\n", length, width);
            printf("01B Area: %0.2f\n", area);
            if (area >= largest){                
                printf("02 Largest: Length: %d     Width: %d\n", length, width);
                if (length * width > result || area > largest ){
                    largest = area;
                    printf("Setting result from: %d  to  %d\n", result, length * width);
                    result = length * width;
                }
            }
        
        }

        return result;
    }
};


int main(){
    Solution s;

    vector<vector<int>> t1 = {{9,3},{8,6}};
    vector<vector<int>> t2 = {{3,4},{4,3}};

    cout << "Test 1 answer: " << endl << s.areaOfMaxDiagonal(t1) << endl;
    cout << "Test 2 answer: " << endl << s.areaOfMaxDiagonal(t2) << endl;

    return 0;
}
