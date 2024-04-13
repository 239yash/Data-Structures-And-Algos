class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = INT_MIN;
        std::vector<int> nums(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0')
                    nums[j] = 0;
                else 
                    nums[j]++;
            }
            int area = calcArea(nums);
            ans = max(ans, area);
        }
        return ans;
    }

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
    
    int calcArea(vector<int>& heights) {
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



// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.
