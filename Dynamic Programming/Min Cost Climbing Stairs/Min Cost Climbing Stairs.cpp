class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dp(1001, 0);
        return min(func(0, cost, dp), func(1, cost, dp));
    }
    
    int func(int i, std::vector<int>& cost, std::vector<int>& dp) {
        if(i == cost.size() - 1 || i == cost.size() - 2) return cost[i]; // Reached end or end - 1
        if(dp[i] != 0) return dp[i]; // If value exists in dp array
        dp[i] = min(func(i + 1, cost, dp), func(i + 2, cost, dp)) + cost[i]; 
        return dp[i];
    }
};

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.
// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.
