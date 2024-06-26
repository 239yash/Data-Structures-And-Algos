class Solution {
public:
    int dp[201][201];
    int n;
    int func(vector<vector<int>>& grid, int i, int j) {
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        
        for(int k = 0; k < n; k++) {
            if(k == j) continue;
            ans = min(ans, grid[i][k] + func(grid, i + 1, k));
        }
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 1) return grid[0][0];
        int ans = INT_MAX;
        memset(dp, -1, sizeof dp);
        
        for(int j = 0; j < n; j++)
            ans = min(ans, func(grid, 0, j));
        return ans;
    }
};









// Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

// A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

 

// Example 1:


// Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
// Output: 13
// Explanation: 
// The possible falling paths are:
// [1,5,9], [1,5,7], [1,6,7], [1,6,8],
// [2,4,8], [2,4,9], [2,6,7], [2,6,8],
// [3,4,8], [3,4,9], [3,5,7], [3,5,9]
// The falling path with the smallest sum is [1,5,7], so the answer is 13.
// Example 2:

// Input: grid = [[7]]
// Output: 7
 

// Constraints:

// n == grid.length == grid[i].length
// 1 <= n <= 200
// -99 <= grid[i][j] <= 99
