#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <cstdint>

using namespace std;

class Solution {
public:

    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
    string gcdOfStrings(string str1, string str2) {
        string result = "";
        
        if (str1 + str2 != str2 + str1) return "";

        int gcd_len = gcd(str1.length(), str2.length());
        printf("GCD LEN: %d\n", gcd_len);

        result = str1.substr(0, gcd_len);


        return result;

    }
};



int main() {

    Solution s;

    string result = "";

    string ex1a = "ABCABC";
    string ex1b = "ABC";
    result = s.gcdOfStrings(ex1a, ex1b);
    printf("Word 1: %s\nWord 2: %s\nResult: %s\nExpected: %s\n\n", ex1a.c_str(), ex1b.c_str(), result.c_str(), "ABC");

    string ex2a = "ABABAB";
    string ex2b = "ABAB";
    result = s.gcdOfStrings(ex2a, ex2b);
    printf("Word 1: %s\nWord 2: %s\nResult: %s\nExpected: %s\n\n", ex2a.c_str(), ex2b.c_str(), result.c_str(), "AB");

    string ex3a = "LEET";
    string ex3b = "CODE";
    result = s.gcdOfStrings(ex3a, ex3b);
    printf("Word 1: %s\nWord 2: %s\nResult: %s\nExpected: %s\n\n", ex3a.c_str(), ex3b.c_str(), result.c_str(), "none");
    
    string ex4a = "ABCEFG";
    string ex4b = "ABC";
    result = s.gcdOfStrings(ex1a, ex1b);
    printf("Word 1: %s\nWord 2: %s\nResult: %s\nExpected: %s\n\n", ex4a.c_str(), ex4b.c_str(), result.c_str(), "none");

    return 0;
}