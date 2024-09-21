/*
62. Unique Paths
https://leetcode.com/problems/unique-paths/description/
Skills: Dynamic Programming, Algorithms
*/

class Solution {
    public int uniquePaths(int m, int n) {
        int[][] arr = new int[n][m];
        for(int y = 0 ; y < n ; y++){
            for(int x = 0 ; x < m ; x++){
                if(x == 0 || y == 0){
                    arr[y][x] = 1;
                }else{
                    int fromAbove = arr[y-1][x];
                    int fromLeft = arr[y][x-1];
                    arr[y][x] = fromAbove + fromLeft;
                }
            }
        }
        return arr[n-1][m-1];

    }
}