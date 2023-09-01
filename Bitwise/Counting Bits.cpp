class Solution {
public:
    vector<int> countBits(int n) {  
        std::vector<int> v;     
        v.push_back(0);
        for(int i = 1; i <= n; i++) {
            v.push_back(1 + v[i - pow(2, int(log2(i)))]);
        }
        return v;
    }
};










// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

// Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
