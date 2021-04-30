class Solution {
public:
    int numSquares(int w)
    {
        std::vector<int> wt;
        for(int i = 1; i*i <= w; i++)
            wt.push_back(i*i);
        // reverse(wt.begin(), wt.end());
        
        // for(auto x : wt)cout<<x<<" ";cout<<endl;
        int n = wt.size();
        
        int dp[n+1][w+1];
        
        for(int i = 0; i < n+1; i++)
        {
            for(int j = 0; j < w+1; j++)
            {
                if(i == 0 || j == 0)
                {
                    if(i == 0)
                        dp[i][j] = INT_MAX - 1;
                    if(j == 0)
                        dp[i][j] = 0;
                }
                else
                {
                    if(wt[i-1] <= j)
                    {
                        dp[i][j] = min(1 + dp[i][j - wt[i-1]], dp[i-1][j]);
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        
        return dp[n][w];
    }
};
