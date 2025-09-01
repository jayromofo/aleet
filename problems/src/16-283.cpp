#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int x = 0;

        while (left < right){
            // If right is 0 then decrease the index
            if (nums[right] == 0){
                printf("Index %d is 0. Moving to index %d\n", right, right - 1);
                --right;                
            }

            // If Left is not 0 then swap with the Right
            if (nums[left] == 0 && nums[right] != 0){
                printf("Swapping left: [%d: %d] with right [%d: %d]\n", left, nums[left], right, nums[right]);
                x = nums[right];            
                nums[right] = nums[left];
                nums[left] = x;
                printf("Decreasing Right from: %d ", right );               
                --right;                
                printf("To: %d \n", right );               
            }

            // If left is bigger than left + 1 then swap
            if (nums[left] > nums[left+1]){                
                ++left;    
            } 
        }



        printf("[");
        for (auto v : nums){
            printf("%d ", v);
        }
        printf("]\n");
    }
};


int main(){
    Solution s;

    vector<int> t1 = {0,1,0,3,12};
    vector<int> t2 = {0};

    s.moveZeroes(t1);
    s.moveZeroes(t2);

    return 0;
}