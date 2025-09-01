#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        std::string s = std::to_string(num);
        for (char &c : s) {
            if (c == '6') { c = '9'; break; }
        }
        return std::stoi(s);
    }
};


int main(){
    Solution s;

    int t1 = 9669;
    int t2 = 9996;
    int t3 = 9999;


    printf("Test 1: %d\nExpected: '9969'\nResult: %d\n\n,", t1, s.maximum69Number(t1));
    printf("Test 2: %d\nExpected: '9999'\nResult: %d\n\n", t2, s.maximum69Number(t2));
    printf("Test 3: %d\nExpected: '9999'\nResult: %d\n\n", t3, s.maximum69Number(t3));

    return 0;
}