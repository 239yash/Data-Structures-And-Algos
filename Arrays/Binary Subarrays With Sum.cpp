class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
    
    int atMost(vector<int>& nums, int goal) {
        int start = 0, end = 0, ans = 0,count = 0;
        if (goal < 0)
            return 0;
        while(end<nums.size()) {
            count += nums[end];
            while(count > goal) {
                count -= nums[start];
                start++;
            }
            ans += end - start + 1;
            end++;
        }
        return ans;
    }
};



// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15
