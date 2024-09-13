/*
1310. XOR Queries of a Subarray
https://leetcode.com/problems/xor-queries-of-a-subarray/description/
Skills: Algorithms
*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ret;
        vector<int> prefix;

        int amt = 0;
        for(int i : arr){
            amt ^= i;
            prefix.push_back(amt);
        }
        for(vector<int> vi : queries){
            int val = arr[vi[0]] ^ prefix[vi[0]] ^ prefix[vi[1]];
            ret.push_back(val);
        }
        return ret;
    }
};

