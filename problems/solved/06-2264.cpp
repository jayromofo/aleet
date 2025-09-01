#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>
#include <cassert>
#include <bits/c++config.h>
#include <algorithm>



using namespace std;


class Solution {
public:
    string largestGoodInteger(string num) {
        string current = "";
        string result = "";
        int icount = 0;
        int nextIndex;
        char next;

        if (num.size() == 0 || num.empty()){
            return result;
        }

        for (uint16_t i = 0; i < num.size(); i++){
            icount = 0;
            nextIndex = i + 1;
            next = num[nextIndex];

            if (num[i] == next){
                icount = 2;
                ++nextIndex;
                if (next == num[nextIndex]){
                    icount = 3;                    
                }

                if (icount == 3){
                    current = string(3, num[i]);
                    if (result == "" || current[0] >= result[0]){
                        result = current;
                    }
                }

            }
        }

        return result;
    }
};




int main(){
    Solution s;

    string t1 = "6777133339";
    string t2 = "2300019";
    string t3 = "42352338";

    string result = "";

    printf("-------------------------------------------\n");
    printf("--- Testing -------------------------------\n");
    printf("-------------------------------------------\n");
    result = s.largestGoodInteger(t1);
    printf("Num: %s\t Expected: %s\n Result: %s\n", t1.c_str(), "777", result.c_str());
    printf("-------------------------------------------\n");
    result = "";

    result = s.largestGoodInteger(t2);
    printf("Num: %s\t Expected: %s\n Result: %s\n", t2.c_str(), "000", result.c_str());
    printf("-------------------------------------------\n");
    result = "";

    result = s.largestGoodInteger(t3);
    printf("Num: %s\t Expected: %s\n Result: %s\n", t3.c_str(), " ", result.c_str());
    printf("-------------------------------------------\n");
    result = "";

  

    return 0;
}

