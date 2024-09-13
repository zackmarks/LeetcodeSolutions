/*
2220. Minimum Bit Flips to Convert Number
https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
Skills: Bitwise operations
*/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal;
        int count = 0;
        while (temp > 0){
            if(temp % 2 == 1) count++;
            temp /= 2;
        }
        return count;
    }
};

