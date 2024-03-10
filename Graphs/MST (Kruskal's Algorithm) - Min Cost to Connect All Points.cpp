class UnionFind {
public:
    std::vector<int> representative;
    std::vector<int> size;
    
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            representative.push_back(i);
            size.push_back(1);
        }
    }
    
    int find(int u) {
        if (representative[u] == u)
            return u;
        return representative[u] = find(representative[u]);
    }
    
    void combine(int u, int v) {
        int uP = find(u);
        int vP = find(v);
        if (uP == vP) return;
        if (size[uP] > size[vP]) {
            representative[vP] = uP;
            size[uP] += size[vP];
        } else {
            representative[uP] = vP;
            size[vP] += size[uP];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        UnionFind uf(n);
        std::vector<pair<int, pair<int, int>>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = getDistance(points[i], points[j]);
                adj.push_back({dist, {i, j}});
            }
        }
        sort(adj.begin(), adj.end());
        int sum = 0;
        for (auto x : adj) {
            int wt = x.first;
            int u = x.second.first;
            int v = x.second.second;
            if (uf.find(u) != uf.find(v)) {
                sum += wt;
                uf.combine(u, v);
            }
        }
        return sum;
    }
    
    int getDistance(vector<int>& point1, vector<int>& point2) {
        return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
    }
};




// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

// Example 1:


// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation: 

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.
// Example 2:

// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18
