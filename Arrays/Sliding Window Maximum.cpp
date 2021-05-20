class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        std::vector<int> ans;
        std::deque<int> dq;

        for(int i = 0; i < k; i++)
        {
            while(dq.size() && dq.back() < nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
        }
        
        ans.push_back(dq.front());
        
        for(int i = k; i < nums.size(); i++)
        {
            if(dq.front() == nums[i - k])
            {
                dq.pop_front();
            }
            
            while(dq.size() && dq.back() < nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
            
            ans.push_back(dq.front());
        }
        
        return ans;
    }
};

/*

You are given an array of integers nums, there is a sliding window of size k which
is moving from the very left of the array to the very right.
You can only see the k numbers in the window.
Each time the sliding window moves right by one position.

Return the max sliding window.
Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

*/
