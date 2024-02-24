class UnionFind {
    public:
    std::vector<int> representative;
    std::vector<int> rank;

    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            representative.push_back(i);
            rank.push_back(0);
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
        if (rootU == rootV) {
            return;
        }
        
        if (rank[rootU] > rank[rootV]) {
            representative[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            representative[rootU] = rootV;
        } else {
            representative[u] = v;
            rank[v]++;
        }
    }
};
