#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxX = *max_element(candies.begin(), candies.end());
        cout << "Max is: " << maxX << endl;
        for (uint16_t i = 0; i < candies.size(); i++){
            if (candies[i] + extraCandies >= maxX){
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};



int main(){

    Solution s;
    vector<bool> result;

    vector<int> t1 = {2,3,5,1,3};
    vector<int> t2 = {4,2,1,1,2};
    vector<int> t3 = {12,1,12};

    result = s.kidsWithCandies(t1, 3); // [true,true,true,false,true] 
    for (auto v : result){
        printf("%s ", v ? "true" : "false");
    }
    printf("\n\n");
    result.clear();

    result = s.kidsWithCandies(t2, 1); // [true,false,false,false,false] 
    for (auto v : result){
        printf("%s ", v ? "true" : "false");
    }
    printf("\n\n");
    result.clear();

    result = s.kidsWithCandies(t3, 10); // [true,false,true]
    for (auto v : result){
        printf("%s ", v ? "true" : "false");
    }
    printf("\n\n");
    result.clear();
    printf("Hello World\n");

    return 0;

}





















































