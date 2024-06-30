class UnionFind {
    public:
    std::vector<int> parent;

    UnionFind(int n) {
        for (int i = 0; i < n + 1; i++) {
            parent.push_back(i);
        }
    }

    int find(int u) {
        if (parent[u] == u) 
            return u;
        return parent[u] = find(parent[u]);
    }

    bool combine(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) {
            return false;
        } 
        
        parent[rootU] = rootV;  
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n), bob(n);
        int temp = 0;
        for (auto x : edges) {
            int type = x[0];
            int u = x[1];
            int v = x[2];
            
            if (type == 3) {
                bool a = alice.combine(u, v);
                bool b = bob.combine(u, v);
                temp += (a || b);
            }
        }
        
        for (auto x : edges) {
            int type = x[0];
            int u = x[1];
            int v = x[2];
            
            if (type == 1)
                temp += alice.combine(u, v);
            else if (type == 2)
                temp += bob.combine(u, v);
        }
        
        cout<<temp<<endl;
        // cout<<alice.components<<" "<<bob.components<<endl;
        int rootAlice = alice.find(1);
        int rootBob = bob.find(1);
        for(int i = 1; i <= n; i++) {
            if(rootAlice != alice.find(i))
                return -1;
            if(rootBob != bob.find(i))
                return -1;
        }
        return edges.size() - temp;
    }
};









// Alice and Bob have an undirected graph of n nodes and three types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

 

// Example 1:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output: 2
// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
// Example 2:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// Output: 0
// Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
// Example 3:



// Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// Output: -1
// Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 

 

// Constraints:

// 1 <= n <= 105
// 1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
// edges[i].length == 3
// 1 <= typei <= 3
// 1 <= ui < vi <= n
// All tuples (typei, ui, vi) are distinct.
