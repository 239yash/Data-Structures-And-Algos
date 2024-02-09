class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            for (auto x : times) {
                int u = x[0];
                int v = x[1];
                int wt = x[2];
                
                if (dist[u - 1] != INT_MAX && dist[u - 1] + wt < dist[v - 1]) {
                    dist[v - 1] = dist[u - 1] + wt;
                }
            }
        }
        
        for (auto x : dist) {
            ans = max(ans, x);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
