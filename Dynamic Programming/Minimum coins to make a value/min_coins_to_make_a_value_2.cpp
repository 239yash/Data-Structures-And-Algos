int MinCoin(vector<int>nums, int v)
	{
	    int m = nums.size();
	    int coins[nums.size()];
	    for(int i = 0; i < nums.size(); i++)
	    coins[i] = nums[i];
	    
	    int ans = coinsr(coins,m,v);
	    if(ans == INT_MAX - 1)
	    return -1;
	    else
	    return ans;
	}
	
	int coinsr(int coins[], int m, int v) 
	{
	    int dp[m+1][v+1];
	    for(int i = 0; i < m+1; i++)
	    {
	        for(int j = 0; j < v+1; j++)
	        {
	            if(j == 0)
	            {
	                dp[i][j] = 0;
	            }
	            
	            if(i == 0)
	            {
	                dp[i][j] = INT_MAX - 1;
	            }
	            
	            if(i == 1)
	            {
	                if(j % coins[0] == 0)
	                {
	                    dp[i][j] = j / coins[0];
	                }
	                else
	                {
	                    dp[i][j] = INT_MAX - 1;
	                }
	            }
	        }
	    }
	    
	    
	    for(int i = 2; i <= m; i++)
	    {
	        for(int j = 1; j <= v; j++)
	        {
	            if(coins[i-1] <= j)
	            {
	                dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
	            }
	            else
	            {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    return dp[m][v];
	} 
