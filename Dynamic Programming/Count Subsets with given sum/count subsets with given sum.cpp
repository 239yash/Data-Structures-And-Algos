long long perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        long long MOD = pow(10,9) + 7;
        long long dp[n+1][sum+1];
        for(long long i = 0; i < n+1; i++)
        {
            for(long long j = 0; j < sum+1; j++)
            {
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 0;
            }
        }
        
        for(long long i = 1; i < n+1; i++)
        {
            for(long long j = 1; j < sum+1; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = max((dp[i-1][j - arr[i-1]] + 1)%MOD, dp[i-1][j]%MOD);
                }
                else
                {
                    dp[i][j] = dp[i-1][j]%MOD;
                }
            }
        }
        
        for(long long i = 0; i < n+1; i++)
        {
            for(long long j = 0; j < sum+1; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][sum]%MOD;
	}
