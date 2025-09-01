#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        auto w1 = word1.begin();
        auto w2 = word2.begin();

        int x = word1.length();
        int y = word2.length();
        int longest = x > y ? x : y;


        for (int i = 0; i < longest; i++){
            if (w1 != word1.end()){
                result += *w1;
                w1++;
            }
            if (w2 != word2.end()){
                result += *w2;
                w2++;
            }
            
        }
        
        return result; 
    }
};

int main() {
    Solution s;
    string result = "";

    string word1 = "abcd";
    string word2 = "pq";


    result = s.mergeAlternately(word1, word2);

    cout << "Answer is: " << result << endl;


    return 0;

}