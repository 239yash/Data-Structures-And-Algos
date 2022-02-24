class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int dp[s.size() + 1][s.size() + 1];
        // for(int i = 0; i <= s.size(); i++) {
        //     for(int j = 0; j <= s.size(); j++) {
        //         if(i == 0 || j == 0) dp[i][j] = 0;
        //     }
        // }

        int maxLen = INT_MIN;
        
        for(int i = 0; i <= s.size(); i++) {
            for(int j = 0; j <= s.size(); j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else {
                                 if(s1[i - 1] == s2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
                if(dp[i][j] > maxLen) {
                    maxLen = dp[i][j];   
                }
                }
            }
        }

        
        return maxLen;
    }
};
