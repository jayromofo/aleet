#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>
#include <map>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        map<char,int> clength;
        int count = 0;

        if (chars.size() == 1){
            return 1;
        }

        for (uint16_t i = 0; i < chars.size(); i++){
            
            // Add if first entry
            if (s == ""){
                s += chars[i];
                count += 1;
            } 
            
            if (chars[i] == chars[i-1]){
                count += 1;
            }

            if (i == chars.size() - 1){
                if (count > 1){
                    s += to_string(count);
                }
            }

            // If the prev one is not the same character, record the character and the size
            if (chars[i] != chars[i-1]){
                s += chars[i];
                if (count > 1)
                    s += to_string(count);                
            } 

            
        }

        chars.clear();

        for (char& c : s){
            chars.push_back(c);
            printf("%c", c);
        }
        cout << endl;
        cout << endl;
        
        
        return chars.size();
    }
};


int main(){
    Solution s;

    vector<char> t1 = {'a','a','b','b','c','c','c'};
    int r1 = s.compress(t1);
    vector<char> t2 = {'a'};
    int r2 = s.compress(t2);
    vector<char> t3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int r3 = s.compress(t3);


   

    return 0;
}