#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool result = false;
        int remaining = n;
        vector<int> newBed = flowerbed;
        uint16_t end = flowerbed.size() - 1;

        if (n == 0){
            printf("debug 1\n");
            return true;
        }

        if (flowerbed.size() == 1 && flowerbed[0] == 1 && n == 1){
            printf("debug 2\n");
            return false;
        }

        if (flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1){
            printf("debug 3\n");
            return true;
        }

        // Check first index
        if (flowerbed[0] == 0 && flowerbed[1] == 0){
            printf("debug 4\n");
            flowerbed[0] = 1;
            remaining -= 1;     
            if (checkComplete(remaining)) return true;                
        }

        // Check last index
        if (flowerbed[end] == 0 && flowerbed[end-1] == 0){
            printf("debug 5\n");
            flowerbed[end] = 1;                
            remaining -= 1;    
            if (checkComplete(remaining)) return true;                
        }

        for (uint16_t i = 0; i < flowerbed.size(); i++){       
            

            for (uint16_t j = i + 1; j < flowerbed.size(); j++){
                         

                if (checkComplete(remaining)){            
                    result = true;
                    return result;
                }

                if (j + 1 > end){                    
                    return checkComplete(remaining);
                }
                

                if (flowerbed[j] == 0){
                    if (flowerbed[j-1] == 0 && flowerbed[j+1] == 0){
                        printf("debug 8\n");
                        flowerbed[j] = 1;
                        remaining -= 1;    
                        checkComplete(remaining);                   
                    }
                }
            }
        }

        return result;
    }

    bool checkComplete(int n){
        return n == 0 ? true : false;
    }
};





int main(){

    Solution s;
    bool result = false;
   
    printf("Hello World\n");


    vector<int> t1 = {1,0,0,0,1};
    vector<int> t2 = {1,0,0,0,1};
    vector<int> t3 = {0,0,1,0,0};

    result = s.canPlaceFlowers(t1, 1);
    printf("Test 1: %s\n\n", result ? "true" : "false");
    result = s.canPlaceFlowers(t2, 2);
    printf("Test 2: %s\n\n", result ? "true" : "false");
    result = s.canPlaceFlowers(t3, 1);
    printf("Test 3: %s\n\n", result ? "true" : "false");

    return 0;

}
