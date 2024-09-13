/*
1684. Count the Number of Consistent Strings
https://leetcode.com/problems/count-the-number-of-consistent-strings/description/
Skills: Strings, Hashmaps
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> goodLetters;
        for(char c : allowed){goodLetters[c] = true;}

        int amt = 0;
        for(string w : words){
            bool goodSoFar = true;
            for(char c : w){
                if(!goodLetters[c]) goodSoFar = false;
            }
            amt += goodSoFar;
        }
        return amt;
    }
};

