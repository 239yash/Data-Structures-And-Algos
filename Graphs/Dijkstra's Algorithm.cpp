class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];

        for(auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
        }


        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        while(!pq.empty()){

            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){

                int adjNode = it.first;
                int edWt = it.second;

                if(time + edWt < dist[adjNode]){
                    dist[adjNode] = time + edWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = -1;
        for(int i=1;i<=n;i++){
            ans = max(ans, dist[i]);
        }
        return ans == 1e9 ? -1 : ans;

    }
};
