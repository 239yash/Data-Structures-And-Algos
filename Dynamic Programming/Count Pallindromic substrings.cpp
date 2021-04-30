class Solution {
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int res = 0;
        bool dp[n][n];
        
        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = i; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    if(j - i < 2 || dp[i+1][j-1] == true)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                else
                    dp[i][j] = false;
                
                if(dp[i][j]) ++res;
            }
        }
        
        return res;
    }
};
