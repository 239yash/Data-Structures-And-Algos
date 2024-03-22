class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() <= 1) 
            return 1;
        
        int n = arr.size();
        std::vector<int> dp(n, 0);
        dp[0] = 1;
        arr[0] != arr[1] ? dp[1] = 2 : dp[1] = 1;
        int ans = max(dp[0], dp[1]);
        
        for (int i = 2; i < n; i++) {
            if ((arr[i - 2] < arr[i - 1] && arr[i - 1] > arr[i]) ||
               (arr[i - 2] > arr[i - 1] && arr[i - 1] < arr[i])) {
                dp[i] = dp[i - 1] + 1;
            } else {
                arr[i] != arr[i - 1] ? dp[i] = 2 : dp[i] = 1;
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};





// Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

// A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

// More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

// For i <= k < j:
// arr[k] > arr[k + 1] when k is odd, and
// arr[k] < arr[k + 1] when k is even.
// Or, for i <= k < j:
// arr[k] > arr[k + 1] when k is even, and
// arr[k] < arr[k + 1] when k is odd.
 

// Example 1:

// Input: arr = [9,4,2,10,7,8,8,1,9]
// Output: 5
// Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
// Example 2:

// Input: arr = [4,8,12,16]
// Output: 2
// Example 3:

// Input: arr = [100]
// Output: 1
