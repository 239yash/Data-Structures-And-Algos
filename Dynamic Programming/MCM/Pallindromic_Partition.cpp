int dp[502][502];
    int palindromicPartition(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        memset(dp,-1, sizeof(dp));
        return pall(s, i, j);
    }
    
    int pall(string s, int i, int j)
    {
        if(i >= j)
            // return dp[i][j] = 0;
            return 0;
        if(isPalindrome(s,i,j))
            return dp[i][j] = 0;
            // return 0;
            
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int mini = INT_MAX;
        int temp;
        for(int k = i; k <= j-1; k++)
        {
            temp = pall(s,i,k) + pall(s,k+1,j) + 1;
            mini = min(temp, mini);
        }
        return dp[i][j] =  mini;
    }
    
    bool isPalindrome(string s, int i, int j) 
    {
        int l = i; 
        int h = j; 
        while (h > l) 
        { 
            if (s[l++] != s[h--]) 
            {
                return false; 
            } 
        } 
        return true;
    } 
