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
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV)
            return;
        if (size[rootU] > size[rootV]) {
            representative[rootV] = rootU;
            size[rootU] += size[rootV];
            size[rootV] = 0;
        } else {
            representative[rootU] = rootV;
            size[rootV] += size[rootU];
            size[rootU] = 0;           
        }
    }
};



class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int ans = 0;
        UnionFind uf(stones.size());
        for (int i = 0; i < stones.size(); i++) {
            for (int j = i + 1; j < stones.size(); j++) {
                int x1 = stones[i][0];
                int y1 = stones[i][1];
                int x2 = stones[j][0];
                int y2 = stones[j][1];
                
                if ((x1 == x2 || y1 == y2) && uf.find(i) != uf.find(j)) {
                    uf.combine(i, j);
                }
            }
        }
        for (auto x : uf.size) {
            if (x > 1)
                ans += (x - 1);
        }
        return ans;
    }
};





// On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

// Example 1:

// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
// Example 2:

// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// Output: 3
// Explanation: One way to make 3 moves is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,0].
// 2. Remove stone [2,0] because it shares the same column as [0,0].
// 3. Remove stone [0,2] because it shares the same row as [0,0].
// Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
// Example 3:

// Input: stones = [[0,0]]
// Output: 0
// Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 

// Constraints:

// 1 <= stones.length <= 1000
// 0 <= xi, yi <= 104
// No two stones are at the same coordinate point.
