class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        if (redEdges.size() == 0 && blueEdges.size() == 0) {
            std::vector<int> ans(n, -1);
            ans[0] = 0;
            return ans;
        }
        std::vector<vector<pair<int, int>>> adj(n);
        // red - true & blue - false terminology
        for (auto x : redEdges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back({v, 1});
        }
        for (auto x : blueEdges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back({v, 0});
        }
        
        
        std::queue<vector<int>> q;
        q.push({0, -1, 0});
        
        std::vector<int> redVis(n, 0);
        std::vector<int> blueVis(n, 0);
        std::vector<int> ans(n, INT_MAX);
        ans[0] = 0;
        
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            
            int u = top[0];
            int color = top[1];
            int stage = top[2];
            ans[u] = min(ans[u], stage);
            
            for (auto x : adj[u]) {
                int v = x.first;
                int newColor = x.second;
                if (color == -1 || color != newColor) {
                    if (newColor) {
                        if (redVis[v]) continue;
                        redVis[v] = true;
                        q.push({v, newColor, stage + 1});
                    } else if (!newColor) {
                        if (blueVis[v]) continue;
                        blueVis[v] = true;
                        q.push({v, newColor, stage + 1});    
                    }
                }
            }
        }
        for (int i = 0; i < ans.size(); i++)
            if (ans[i] == INT_MAX)
                ans[i] = -1;
        return ans;
    }
};




// You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

// You are given two arrays redEdges and blueEdges where:

// redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
// blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
// Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

 

// Example 1:

// Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
// Output: [0,1,-1]
// Example 2:

// Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
// Output: [0,1,-1]
