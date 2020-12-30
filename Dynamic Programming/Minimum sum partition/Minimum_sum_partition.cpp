	int minDiffernce(int arr[], int n) 
	{ 
	    // Your code goes here
	    int sum = accumulate(arr, arr + n, 0);
	    
	    bool dp[n+1][sum+1];
	    for(int i = 0; i < n+1; i++)
        {
            for(int j = 0; j < sum+1; j++)
            {
                if(i == 0)
                {
                    dp[i][j] = false;
                }
                
                if(j == 0)
                {
                    dp[i][j] = true;
                }
            }
        }
        
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 1; j < sum+1; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
	    
	    int maxi = -1;
	    for(int i = 0; i <= (sum)/2; i++)
	    {
	        if(dp[n][i] == true)
	        {
	            maxi = max(maxi, i);
	        }
	    }
	    
	    return (sum - 2 * maxi);
	} 
