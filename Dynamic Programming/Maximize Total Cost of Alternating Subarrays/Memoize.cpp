class Solution {
public:
    long long dp[100001][2];
    long long maximumTotalCost(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return func(0, nums, false);
    }
    
    long long func(int index, vector<int>& nums, bool takeNegative) {
        if (index >= nums.size())
            return 0;
        if (dp[index][takeNegative] != -1) 
            return dp[index][takeNegative];
        if (takeNegative) {
            long long takeNeg = func(index + 1, nums, false) - nums[index];
            long long withoutNeg = func(index + 1, nums, true) + nums[index];
            return dp[index][takeNegative] = max(takeNeg, withoutNeg);
        }
        return dp[index][takeNegative] = func(index + 1, nums, true) + nums[index];
    }
};
