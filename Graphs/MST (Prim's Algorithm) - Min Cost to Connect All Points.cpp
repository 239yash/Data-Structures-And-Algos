class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> adj(points.size());
        for (int i = 0; i < points.size() - 1; i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int distance = getDistance(points[i], points[j]);
                adj[i].push_back(make_pair(j, distance));
                adj[j].push_back(make_pair(i, distance));
            }
        }
        
        vector<bool> visited(points.size(), false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        int sum  = 0;
        
        while(!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            
            int wt = top.first;
            int u = top.second;
            
            if (visited[u]) continue;
            visited[u] = true;
            sum += wt;
            
            for (auto x : adj[u]) { 
                int adjNode = x.first; 
                int eWt = x.second; 
                
                if (visited[adjNode] == false)
                    pq.push(make_pair(eWt, adjNode)); 
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
