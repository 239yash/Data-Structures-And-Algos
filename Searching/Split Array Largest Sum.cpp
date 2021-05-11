class Solution {
public:
    int splitArray(vector<int>& nums, int m)
    {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int ans;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(func(nums, m, mid))
            {
                right = mid - 1;
                ans = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return ans;
    }
    
    bool func(vector<int>& nums, int m, int mid)
    {
        int count = 1;
        int sum  = 0;
        int i = 0;
        
        while(i < nums.size())
        {
            if(sum + nums[i] <= mid)
            {
                sum = sum + nums[i];
            }
            else
            {
                sum = nums[i];
                count++;
            }
            
            i++;
            if(count > m)
                return false;
        }
    
        return true;
    }
};


/*
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.


Example 2:
Input: nums = [1,2,3,4,5], m = 2
Output: 9


Example 3:
Input: nums = [1,4,4], m = 3
Output: 4

*/
