class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        std::vector<int> topo(graph.size(), 0);
        std::vector<vector<int>> adj(graph.size());
        std::vector<int> res;
        for (int i = 0; i < graph.size(); i++) {
            topo[i] = topo[i] + graph[i].size();
            for (auto x : graph[i]) {
                adj[x].push_back(i);
            }
        }
        
        // for (int i = 0; i < topo.size(); i++) {
        //     cout<<topo[i]<<" ";
        // }
        // cout<<endl;
        // for (int i = 0; i < adj.size(); i++) {
        //     for (int j = 0; j < adj[i].size(); j++) {
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        std::queue<int> q;
        for (int i = 0 ; i < topo.size(); i++) {
            if (topo[i] == 0) {
                q.push(i);
                topo[i] = -1;
            }
        }
        
        while(q.size() > 0) {
            int front = q.front();
            q.pop();
            res.push_back(front);
            for (auto x : adj[front]) {
                topo[x]--;
                if (topo[x] == 0) {
                    q.push(x);
                    topo[x] = -1;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
