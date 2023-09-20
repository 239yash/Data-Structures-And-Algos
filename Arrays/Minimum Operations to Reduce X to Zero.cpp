class Solution {
public:
    int minOperations(vector<int>& nums, int targetSum) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - targetSum; 
        if (target < 0) return -1;
        if (target == 0) return nums.size(); 
        
        int ans = INT_MAX;
        int currentSum = 0;
        int i = 0, j = 0;
        int n = nums.size();

        while (j < nums.size()) {
            currentSum += nums[j];
            j++;
            while (currentSum > target && i < nums.size()) {
                currentSum -= nums[i];
                i++;
            }

            if (currentSum == target)
                ans = min(ans, n - (j - i));
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
