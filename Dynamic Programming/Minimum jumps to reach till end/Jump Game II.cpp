class Solution {
public:
    int jump(vector<int>& nums) {
        std::vector<int> dp(nums.size(), -1);
        return func(nums, 0, dp);
    }

    int func(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if (index == nums.size() - 1) {
            return 0;
        }
        if (nums[index] == 0) {
            return -1;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int count = nums[index];
        int temp = INT_MAX;
        while (count > 0) {
            int temp1 = func(nums, index + count, dp);
            if (temp1 != -1) {
                temp = min(temp, temp1);
            }
            count--;
        }

        return dp[index] = temp == INT_MAX ? -1 : temp + 1;
    }
};
