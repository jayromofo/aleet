#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>

using namespace std;

static int count;

class Solution {
    bool checkRow(vector<int>& row){
        bool result = true;

        for (auto it = row.begin(); it != row.end(); ++it){
            if (*it == 0){
                printf("Row failed\n");
                result = false;
            } else {
                printf("[1] Point!\n");
                ++count;
            }
        }
        if (result == true) printf("Row Passed\n");
        return result;
    }

    //  [0][0]   [0][1]     [0][2]
    //  [1][0]   [1][1]     [0][2]
    //  [2][0]   [2][1]     [0][2]

    bool checkSquare(vector<vector<int>>& matrix, uint16_t col, uint16_t row){
        bool result = true;
        int end = row + 2;
        vector<int> test;
        bool lastPass = false;
        int pass = 0;

        printf("\n\n--------------------------------------------\n");
        printf("Checking for perfect square\n");
        for (uint16_t i = 0; i < 3; i++){
            // col += i;
            // row += i;

            printf("\n--------------------------\n");
            printf("[%d] [%d] [%d] \n",matrix[col][row]);
            printf("[%d] [%d] [%d] \n",matrix[col+1][row]);
            printf("[%d] [%d] [%d] \n",matrix[col+2][row]);
            printf("\n--------------------------\n");
            
            // printf("------adding to vec:  \n[%d]\n[%d]\n[%d]\n --------\n", matrix[col][row], matrix[col][row], matrix[col][row]);

            // test.push_back(matrix[col][row]);
            // test.push_back(matrix[col+1][row]);
            // test.push_back(matrix[col+2][row]);
        }

        // for (auto it = test.begin(); it != test.end(); ++it){
        //     if (*it == 0){
        //         printf("Not a 3x3");
        //         return false;                

        //     }
        // }



        return result;        
    }
    

public:
    // static int count;
    int countSquares(vector<vector<int>>& matrix) {        
        // int count = 0;
        count = 0;
        int result = 0;
        bool columnCheck = false; 

        
        auto dupe = matrix;

        for (uint16_t i = 0; i < matrix.size(); i++){
            columnCheck = true;
            printf("Checking Row: %d\n", i);
            
            // Pass maxtrix[i]
            if (checkRow(dupe[i])) { ++count; };
            for (uint16_t k = 0; k < matrix.size(); k++){
                // if k < length of x - 2
                if (k < matrix.size() - 3 && i < matrix[i].size() - 3){
                    if (checkSquare(dupe,i,k)){
                        printf("Point: 3x3 Square");
                        ++count;
                    }
                }
                
                printf("Checking Column: [%d,%d]\n", k,i);

                if(matrix[k][i] == 0){
                    result = false;
                }
            }
            if (columnCheck) {
                printf("Point for column check. Column [%d]\n\n", i);
                ++count;
            }

            // Check for the triple.
            // Size = 4 - 3;  1  [0]

            //              size 4
            // i [0,1,2,3] < size      
            // 
        
            // k  [0] [1] 
            //    
            // maxIndex = 3; 3 - 2   size - 3
            // max = [0][1]

            
        }

        /*
        for (uint16_t i = 0; i < matrix.size(); i++){
            ySize = matrix.size(); // This is actually the Y size
            xSize = matrix[i].size();            

            printf("Row: %d\t\n", i + 1);
            printf("X Size: %d\n", xSize);
            printf("Y Size: %d\n", ySize);  

            for (uint16_t j = 0; j < matrix[i].size(); j++)
            // If it is a 1
            if (matrix[i][j] == 1){
                ++count;
            }

            // search the column for points
            for (uint16_t k = 0; k < matrix.size(); k++){
                
            }
        
            
        }
        */

        // Check the column

        result = count;

        return result;
    }
};


int main(){
    Solution s;

    vector<vector<int>> t1 = { {0,1,1,1}, {1,1,1,1}, {0,1,1,1}};
    vector<vector<int>> t2 = { {1,0,1}, {1,1,0}, {1,1,0}};    

    printf("--------------------------------------------------\n");
    int r1 = s.countSquares(t1);
    printf("--------------------------------------------------\n\n");
    printf("Test 1 \nTotal: %d\n", r1);
    printf("--------------------------------------------------\n");
    int r2 = s.countSquares(t2);
    printf("--------------------------------------------------\n\n");
    printf("Test 2 \nTotal: %d\n", r2);
    printf("--------------------------------------------------\n\n");
    

    return 0;
}