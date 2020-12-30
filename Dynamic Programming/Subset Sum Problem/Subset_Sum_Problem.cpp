int equalPartition(int n, int arr[])
    {
        int sum = accumulate(arr, arr + n, 0);
        if(sum % 2 != 0)
            return 0;
        sum = sum / 2;
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
        
        for(int i = 0; i < n+1; i++)
        {
            for(int j = 0; j < sum+1; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return dp[n][sum];
    }
