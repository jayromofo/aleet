#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdint>
#include <random>

using namespace std;

static int rollPoints(int maxPts){
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, maxPts);

    int result = dis(gen);

    cout << "rolled a " << result << endl;

    return result;
}


struct Game {
    int targetPoints;
    int stopPoints;
    int maxPts;    
};

// Roll 1 100% n < 21 10/10
// Roll 2 100% n < 21 70% 17/20 0.85   needs roll# 3   16/20 0.8
// Roll 3 10%  n < 21 50% 21/30 0.7

// Roll 1 = 0.1 * 10     = 1
// Roll 2a = 0.1 * 17    = 1.7
// Roll 2b = 0.1 * 16    = 1.6
// Roll 3 = 0.1 * 17     = 1.7

// 

class Solution {
public:
    double new21Game(int max, int stopPoints, int maxPts) {
        double result = 0;
        int sum = max;
        int alice = 0;
        int rolls = 0;
        int roll = 0;
        double probability = 0.0;

        double maxTotal = maxPts;

        // roll = rollPoints(maxPts);
        // probability = 0.1;
        // alice = roll;
        // ++rolls;

        while (sum > 0){
            sum -= maxPts;
            ++rolls;
        }

        // if (rolls > 1){
        //     int roll2 = stopPoints / maxPts;
        //     result = probability * roll2;
        // } else {
            maxTotal = (maxTotal * rolls);
            printf("Total Points: %d\n", alice);
            printf("Number of Rolls: %d\n", rolls);
            result = max / maxTotal;
            
            printf("Probablility %d / %2.f = %0.2f\n", max, maxTotal, result);        
        // }      

        return result;

    }
};




int main(){
    Solution s;

    Game t1 = {10, 1, 10};
    Game t2 = {6, 1, 10};
    Game t3 = {21, 17, 10};

    double a1 = 0.0;
    double a2 = 0.0;
    double a3 = 0.0; 

    printf("------------------------------------------------------------------\n");
    printf("Test 1: Max: %d\nStop: %d\nMax Points: %d\n", t1.targetPoints, t1.stopPoints, t1.maxPts );
    printf("------------------------------------------------------------------\n");
    a1 = s.new21Game(t1.targetPoints,t1.stopPoints,t1.maxPts);
    printf("------------------------------------------------------------------\n\n");

    printf("------------------------------------------------------------------\n");
    printf("Test 2: Max: %d\nStop: %d\nMax Points: %d\n", t2.targetPoints, t2.stopPoints, t2.maxPts );
    printf("------------------------------------------------------------------\n");
    a2 = s.new21Game(t2.targetPoints,t2.stopPoints,t2.maxPts);
    printf("------------------------------------------------------------------\n\n");

    printf("------------------------------------------------------------------\n");
    printf("Test 3: Max: %d\nStop: %d\nMax Points: %d\n", t3.targetPoints, t3.stopPoints, t3.maxPts );
    printf("------------------------------------------------------------------\n");
    a3 = s.new21Game(t3.targetPoints,t3.stopPoints,t3.maxPts);
    printf("------------------------------------------------------------------\n\n");


    return 0;
}