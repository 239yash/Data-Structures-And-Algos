class Solution {
public:
    vector<int> leftSmaller(vector<int> nums) {
        std::vector<int> ans(nums.size());
        std::stack<int> st;        
        
        for (int i = 0; i < nums.size(); i++) {
            while(!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> rightSmaller(vector<int> nums) {
        std::vector<int> ans(nums.size());
        std::stack<int> st;        
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            while(!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = leftSmaller(heights);
        vector<int> right = rightSmaller(heights);
        
        int ans = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            int l = left[i];
            int r = right[i];
            if(r == -1) r = heights.size();

            int w = r - l - 1;
            ans = max(ans, heights[i] * w);
        }
        
        return ans;
    }
};





// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:


// Input: heights = [2,4]
// Output: 4
 

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104
