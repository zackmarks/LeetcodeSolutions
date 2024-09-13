/*
2028. Find Missing Observations
https://leetcode.com/problems/find-missing-observations/description/
Skills: Math, Algorithms
*/



class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int rollSum = 0;
        int rollCount = 0;
        for(int r : rolls){
            rollSum += r;
            rollCount ++;
        }

        int neededDots = (rollCount+n) * mean - rollSum;
        if(neededDots < n ||neededDots > n*6) return {};

        
        int avgNeededDots = neededDots / n;
        int dotsRemainder = neededDots - avgNeededDots*n;

        vector<int> addedRolls(n, avgNeededDots);
        for(int i = 0 ; i < dotsRemainder ; i++){
            addedRolls[i]++;
        }
        return addedRolls;
    }
};

