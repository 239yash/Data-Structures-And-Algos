class Solution {
public:
    std::unordered_map<string, int> mp;
    int dp[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        for (auto x : wordDict) 
            mp[x]++;
        return func(s, 0);
    }
    
    bool func(string s, int start) {
        if (start == s.size()) return dp[start] = 1;
        if (dp[start] != -1) return dp[start];
        
        bool ans = false;
        for (int i = start; i < s.size(); i++) {
            string temp = s.substr(start, i - start + 1);
            if (mp.find(temp) != mp.end()) {
                ans = ans || func(s, i + 1);
            }
        }
        if (ans) dp[start] = 1;
        else dp[start] = 0;
        return ans;
    }
};






// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
