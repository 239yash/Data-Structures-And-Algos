class Solution {
public:
    string longestPalindrome(string s) {
            ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        int n = s.size();
        int dp[n][n];
        // for(int i = 0; i < n; i++)
        //     for(int j = 0; j < n; j++)
        //         dp[i][j] = 0;
        
        int maxLen = INT_MIN;
        int index = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(i == j) dp[i][j] = 1;
                else {
                    if(s[i] == s[j]) {
                        if(j - i < 2) dp[i][j] = 2;
                        else {
                            if(dp[i + 1][j - 1])
                                dp[i][j] = 2 + dp[i + 1][j - 1];
                            else dp[i][j] = 0;
                        }
                    } else {
                        dp[i][j] = 0;
                    }
                }
                
                if(dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    index = i;
                }
            }
        }
        string ans = "";
        while(maxLen) {
            ans += s[index];
            ++index;
            --maxLen;
        }
        return ans;
    }
};
