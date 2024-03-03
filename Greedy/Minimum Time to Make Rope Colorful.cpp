class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        if (s.size() <= 1) return 0;        
        int start = 0;
        int end = 0;
        int sum = 0;
        int maxValue = INT_MIN;
        int ans = 0;
        
        while (end < s.length()) {
            if (s[end] == s[start]) {
                maxValue = max(maxValue, neededTime[end]);
                sum = sum + neededTime[end];
                end++;
            } else {
                if (end - start > 1) {
                    // cout<<sum<<endl;
                    // cout<<maxValue<<endl;
                    
                    sum = sum - maxValue;
                    ans = ans + sum;
                    // result.push_back(make_pair(start, end - 1));
                }
                sum = 0;
                maxValue = INT_MIN;
                start = end;
            }
        }
        if (end - start > 1) {
            sum = sum - maxValue;
            ans = ans + sum;
            
            sum = 0;
            maxValue = INT_MIN;
            // result.push_back(make_pair(start, end - 1));
        }
        return ans;
    }
    
//     int getMin(vector<int> nums, int i, int j) {
//         auto compare = [](const int& a, const int& b) {
//             return a > b;
//         };
//         std::priority_queue<int, vector<int>, decltype(compare)> pq;
//         for (int k = i; k <= j; k++) {
//             pq.push(nums[k]);
//         }
        
//         int ans = 0;
//         while(pq.size() > 1) {
//             // cout<<pq.top();
//             ans = ans + pq.top();
//             pq.pop();
//         }
//         return ans;
//     }
};









// Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

// Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

// Return the minimum time Bob needs to make the rope colorful.

 

// Example 1:


// Input: colors = "abaac", neededTime = [1,2,3,4,5]
// Output: 3
// Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
// Bob can remove the blue balloon at index 2. This takes 3 seconds.
// There are no longer two consecutive balloons of the same color. Total time = 3.
// Example 2:


// Input: colors = "abc", neededTime = [1,2,3]
// Output: 0
// Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
// Example 3:


// Input: colors = "aabaa", neededTime = [1,2,3,4,1]
// Output: 2
// Explanation: Bob will remove the balloons at indices 0 and 4. Each balloons takes 1 second to remove.
// There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
