/*
739. Daily Temperatures
https://leetcode.com/problems/daily-temperatures/description/
Skills: Stacks, Algorithms
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> prevDays;
        vector<int> ans(temperatures.size(),0);

        for(int i = 0 ; i < temperatures.size() ; i++){
            while(!prevDays.empty() && temperatures[i] > temperatures[prevDays.top()]){
                int t = prevDays.top();
                prevDays.pop();
                ans[t] = i - t;
            }
            prevDays.push(i);
        }
        
        return ans;
    }
};

