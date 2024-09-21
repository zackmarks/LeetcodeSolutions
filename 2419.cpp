/*
2419. Longest Subarray With Maximum Bitwise AND
https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/
Skills: Algorithm
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //problem is asking to find max length subarray of largest number in nums

        int bigNum = nums[0];
        int curLen = 1;
        int bigLen = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] > bigNum){
                bigNum = nums[i];
                curLen = 1;
                bigLen = 1;
            }else if(nums[i] == bigNum){
                curLen++;
                bigLen = max(bigLen, curLen);
            }else{//nums[i] < bigNum
                curLen = 0;
            }
        }
        return bigLen;
    }
};

