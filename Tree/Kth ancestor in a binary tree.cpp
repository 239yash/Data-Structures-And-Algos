class TreeAncestor {
public:
    std::vector<vector<int>> dp1;
    TreeAncestor(int n, vector<int>& parent)
    {
        std::vector<vector<int>> dp(n, vector<int>(20));
        for(int i = 0; i < parent.size(); i++)
        {
            dp[i][0] = parent[i];
        }
        
        for(int j = 1; j < 20; j++)
        {
            for(int i = 0; i < n; i++)
            {
                dp[i][0] = parent[i];
                if (dp[i][j - 1] == -1) dp[i][j] = -1;
                else dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
        
        swap(dp1, dp);
    }
    
    int getKthAncestor(int node, int k)
    {
        for(int i = 0; i < 20; i++)
        {
            if((k >> i) & 1)
            {
                node = dp1[node][i];
                if(node == -1)
                    return -1;
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
