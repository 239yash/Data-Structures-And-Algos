class Solution {
public:
    int dp[1001][1001];
    int getAsciiSum(string s, int end) {
        int sum = 0;
        for (int i = 0; i <= end; i++)
            sum = sum + s[i];
        return sum;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return func(s1.size() - 1, s2.size() - 1, s1, s2);
    }
    
    int func(int i1, int i2, string& s1, string& s2) {
        if (i1 < 0)
            return getAsciiSum(s2, i2);
        if (i2 < 0)
            return getAsciiSum(s1, i1);
        if (dp[i1][i2] != -1)
            return dp[i1][i2];
        
        if (s1[i1] == s2[i2])
            return dp[i1][i2] = func(i1 - 1, i2 - 1, s1, s2);
        
        int temp1 = func(i1 - 1, i2, s1, s2) + s1[i1];
        int temp2 = func(i1, i2 - 1, s1, s2) + s2[i2];
        return dp[i1][i2] = min(temp1, temp2);
    }
};




// Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

// Example 1:

// Input: s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
// Example 2:

// Input: s1 = "delete", s2 = "leet"
// Output: 403
// Explanation: Deleting "dee" from "delete" to turn the string into "let",
// adds 100[d] + 101[e] + 101[e] to the sum.
// Deleting "e" from "leet" adds 101[e] to the sum.
// At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
// If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
 

// Constraints:

// 1 <= s1.length, s2.length <= 1000
// s1 and s2 consist of lowercase English letters.
