#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <functional>
#include <chrono>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zeroCnt = count(begin(nums), end(nums), 0);
        if(zeroCnt > 1) return vector<int>(size(nums));               // Case-1
        for(auto c : nums) 
            if(c) prod *= c;                                          // calculate product of all elements except 0
        for(auto& c : nums)
            if(zeroCnt) c = c ? 0 : prod;                             // Case-2
            else c = prod / c;                                        // Case-3
        return nums;
    }
};





int main(){
    Solution s;

    vector<int> t1 = {1,2,3,4};
    vector<int> t2 = {-1,1,0,-3,3};
    vector<int> t3 = {0, 4, 0};
    vector<int> t4 = s.getTest4();

    printf("---------------------------------------------\n");
    printf("--- Test 1 ----------------------------------\n");
    printf("---------------------------------------------\n");    
    printf("---------------------------------------------\n");
    vector<int> answer1 = s.productExceptSelf(t1);
    cout << "RESULTS: ";
    for (auto& v : answer1){
        cout << v << " ";
    }
    printf("\n\n");
    printf("EXPECTED: [24, 12, 8, 6] \n");
    printf("---------------------------------------------\n\n");

    printf("---------------------------------------------\n");
    printf("---------------------------------------------\n");
    printf("--- Test 2 ----------------------------------\n");
    printf("---------------------------------------------\n");
    vector<int> answer2 = s.productExceptSelf(t2);
    cout << "RESULTS: ";
    for (auto& v : answer2){
        cout << v << " ";
    }
    printf("\n\n");
    printf("EXPECTED: [0,0,9,0,0] \n");
    printf("---------------------------------------------\n\n");

    printf("---------------------------------------------\n");
    printf("---------------------------------------------\n");
    printf("--- Test 3 ----------------------------------\n");
    printf("---------------------------------------------\n");
    vector<int> answer3 = s.productExceptSelf(t3);
    cout << "RESULTS: ";
    for (auto& v : answer3){
        cout << v << " ";
    }
    printf("\n\n");
    printf("EXPECTED: [0,0,0] \n");
    printf("---------------------------------------------\n\n");

    printf("---------------------------------------------\n");
    printf("---------------------------------------------\n");
    printf("--- Test 4 ----------------------------------\n");
    printf("---------------------------------------------\n");
    auto start = chrono::high_resolution_clock::now();
    vector<int> answer4 = s.productExceptSelf(t4);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Test 4: Time Taken -- " << duration.count() << " ms" << endl;
    printf("\n\n");
    printf("EXPECTED: [0,0,0] \n");
    printf("---------------------------------------------\n\n");
    
    

    return 0;
}

