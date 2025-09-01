// https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75

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
    string reverseVowels(string s) {
        string result = s;

        auto it = s.begin();
        char vowels[10]{'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        map<int, char> position;

        for (uint16_t i = 0; i < s.size(); ++i){
            char target = s[i];
            for (uint16_t j = 0; j < 10; j++){
                if (s[i] == vowels[j]){
                    printf("Found %c at index: %d\n", s[i], i);
                    position[i] = s[i];
                }
            }

        }

        for (auto v : position){
            printf("Index: %d | vowel: %c\n", v.first, v.second);
        }

        auto begin = position.begin();
        auto end = position.end();

        auto x = min(begin, end);
        auto y = max(begin, end);

        // printf("min: %d");
        // printf("max: %d");
        

        return result;
    }
};


int main(){
    Solution s;

    string t1 = "IceCreAm";
    string t2 = "leetcode";

    printf("----------------------------------\n");
    printf("--- Test 1: ----------------------\n");
    printf("----------------------------------\n");
    printf("%s\n", t1.c_str());
    string r1 = s.reverseVowels(t1);
    printf("%s: \n", r1.c_str());
    printf("----------------------------------\n\n");
    

    printf("----------------------------------\n");
    printf("--- Test 2: ----------------------\n");
    printf("----------------------------------\n");
    printf("%s\n", t2.c_str());
    string r2 = s.reverseVowels(t2);
    printf("%s: \n", r2.c_str());
    printf("----------------------------------\n\n");

    printf("Test1: %s\n", t1.c_str());
    if (r1 == "AceCreIm"){
        printf("%s: \n\n", "PASSED!!!");
    } else {
        printf("%s: \n\n", "FAILED!!!");
    }
    // assert(r1 == "AceCreIm");

    printf("Test2: %s\n", t2.c_str());
    if (r2 == "leotcede"){
        printf("%s: \n\n", "PASSED!!!");
    } else {
        printf("%s: \n\n", "FAILED!!!");
    }
    // assert(r2 == "leotcede");

    return 0;
}