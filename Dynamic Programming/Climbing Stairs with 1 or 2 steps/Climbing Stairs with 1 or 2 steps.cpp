class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n + 1, 0);
        return func(n, dp);
    }
    
    int func(int n, std::vector<int>& dp) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != 0) return dp[n];
        dp[n - 1] = func(n - 1, dp);
        dp[n - 2] = func(n - 2, dp);
        return dp[n - 1] + dp[n - 2];
    }
};
