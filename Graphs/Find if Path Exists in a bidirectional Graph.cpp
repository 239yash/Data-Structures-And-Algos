// DFS Approach
// Created two boolean variables. I am checking whether both (src and dstn) are in same component or not
// If yes, Then answer is true as graph is bi-directional
// If no, This means that both (src and dstn) are in different components, so no path exists

class Solution {
public:
    bool flag1 = false;
    bool flag2 = false;
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>> graph(n);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        std::vector<int> visited(n, 0);
        for(int i = 0; i < n; ++i) {
            if(visited[i] == 0) {
                dfs(i, s, d, visited, graph);
                if(flag1 && flag2) return true;
                if(flag1 || flag2) return false;
            }
            flag1 = false;
            flag2 = false;
        }
        return false;
    }
    
    void dfs(int i, int s, int d, vector<int>& visited, vector<vector<int>>& graph) {
        if(visited[i]) return;
        visited[i] = 1;
        if(i == s) flag1 = true;
        if(i == d) flag2 = true;
        for(auto x : graph[i]) {
            dfs(x, s, d, visited, graph);
        }
    }
};
