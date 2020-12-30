// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

int minOperations(string a, string b) 
	{ 
	    // Your code goes here
	    int dp[1001][1001];
	    int n = a.length();
	    int m = b.length();
	    for(int i = 0; i < n+1; i++)
	    {
	        for(int j = 0; j < m+1; j++)
	        {
	            if(i == 0 || j == 0)
	                dp[i][j] = 0;
	        }
	    }
	    
	    for(int i = 1; i < n+1; i++)
	    {
	        for(int j = 1; j < m+1; j++)
	        {
	            if(a[i-1] == b[j-1])
	            {
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else
	            {
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	            }
	        }
	    }
	    
	    return (n-dp[n][m]) + (m-dp[n][m]);
	}
