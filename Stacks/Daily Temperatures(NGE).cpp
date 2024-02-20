class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        std::stack<pair<int, int>> st;
        std::vector<int> ans;
        for (int i = t.size() - 1; i >= 0; i--) {            
            int num = t[i];
            while(!st.empty() && st.top().first <= num)
                st.pop();
            if (st.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(abs(st.top().second - i));
            }
            st.push({num, i});
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



// Given an array of integers temperatures represents the daily temperatures, 
// return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
// If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
