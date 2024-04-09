class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        std::vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return func(1, n - 2, nums, dp);
    }
    
    int func(int left, int right, vector<int>& nums, vector<vector<int>>& dp) {
        if (left > right) return 0; 
        if (dp[left][right] != -1) return dp[left][right];
        
        int mx = 0;
        for (int i = left; i <= right; i++) {
            mx = max(mx, 
                     nums[i] * nums[left - 1] * nums[right + 1]
                    + func(left, i - 1, nums, dp)
                    + func(i + 1, right, nums, dp));
        }
        return dp[left][right] = mx;
    }
};


// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums.
// You are asked to burst all the balloons.
// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins.
// If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

 

// Example 1:

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
// Example 2:

// Input: nums = [1,5]
// Output: 10
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// 0 <= nums[i] <= 100
