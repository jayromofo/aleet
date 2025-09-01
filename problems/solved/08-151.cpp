#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <sstream>


using namespace std;

class Solution {
    void trim(std::string& str) {
   // Trim right
   str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
       return !std::isspace(ch);
   }).base(), str.end());
   
   // Trim left
   str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
       return !std::isspace(ch);
   }));
}

public:
    string reverseWords(string s) {
        string result;
        vector<string> words;
        int wordlistlength;
        trim(s);
        printf("Trimmed word: %s\n", s.c_str());

        stringstream ss(s);
        string word;
        while (ss >> word){
            words.push_back(word);
        }

        for (auto& v : words){
            cout << v << endl;
        }

        wordlistlength = words.size();

        for (auto it = words.rbegin(); it != words.rend(); ++it){            
            result += *it + " ";
            printf("Word: %s | result: %s", *it, result.c_str() );
        }
        trim(result);
        

        return result;
    }
};


int main(){
    Solution s;

    string t1 = "the sky is blue";
    string t2 = "  hello world  ";
    string t3 = "a good   example";


    printf("Test 1: %s\nExpected: %s\nResult: %s\n", t1.c_str(), "", s.reverseWords(t1).c_str());
    printf("Test 2: %s\nExpected: %s\nResult: %s\n", t2.c_str(), "", s.reverseWords(t2).c_str());
    printf("Test 3: %s\nExpected: %s\nResult: %s\n", t3.c_str(), "", s.reverseWords(t3).c_str());

    return 0;
}