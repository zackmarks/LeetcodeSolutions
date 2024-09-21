/*
15. 3Sum
https://leetcode.com/problems/3sum/
Skills: Hashmap, Set, Algorithm, Two Pointer
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> lastInstanceOfNum;
        set<vector<int>> svi;
        int s = nums.size();

        for(int i = 0 ; i < s ; i++){
            lastInstanceOfNum[nums[i]] = i;
        }

        for(int i = 0 ; i < s ; i++){
            while(i > 0 && nums[i-1] == nums[i]){
                i++;
                if(i >= s) break;
            }
            for(int j = i+1 ; j < s ; j++){

                int toFind = - nums[i] - nums[j];
                if(lastInstanceOfNum[toFind] > i && lastInstanceOfNum[toFind] > j){
                    vector<int> vi = {nums[i], nums[j], toFind};
                    sort(vi.begin(), vi.end());
                    svi.insert(vi);
                }
            }
        }


        vector<vector<int>> vvi (svi.begin(), svi.end());
        return vvi;
    }
};

