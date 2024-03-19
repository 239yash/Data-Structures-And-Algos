class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        std::vector<int> left(n);
        std::vector<int> right(n);
        std::stack<int> st;
        std::stack<int> stt;
        
        left[0] = 1;
        st.push(0);
        for(int i = 1; i < n; i++) {
            while(!st.empty() && arr[i] < arr[st.top()]) 
                st.pop();
            if(st.empty()) 
                left[i] = i + 1;
            else 
                left[i] = i - st.top();
            st.push(i);
        }
        
        right[n - 1] = 1;
        stt.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while(!stt.empty() && arr[i] <= arr[stt.top()])
                stt.pop();
            if (stt.empty())
                right[i] = n - i;
            else
                right[i] = stt.top() - i;
            stt.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long prod = (left[i] * right[i]) % mod;
            prod = (prod * arr[i]) % mod;
            ans = (ans + prod) % mod;
        }
        return ans;
    }
};





// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
// Since the answer may be large, return the answer modulo 109 + 7.

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444
