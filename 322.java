/*
322. Coin Change
https://leetcode.com/problems/coin-change/description/
Skills: Dynamic Programming, Algorithms
*/

class Solution {

    public int coinChange(int[] coins, int amount) {
        if(amount == 0) return 0;

        int[] leastToMake = new int[amount + 1];
        Arrays.fill(leastToMake, Integer.MAX_VALUE);
        leastToMake[0] = 0;

        for(int i = 0 ; i <= amount ; i++){
            for(int j = 0 ; j < coins.length ; j++){
                if(i - coins[j] >= 0 && leastToMake[i-coins[j]] != Integer.MAX_VALUE){
                    leastToMake[i] = Math.min(leastToMake[i], 1 + leastToMake[i-coins[j]]);
                }
            }
        }
        if(leastToMake[amount] != Integer.MAX_VALUE)
            return leastToMake[amount];
        else
            return -1;
    }
}