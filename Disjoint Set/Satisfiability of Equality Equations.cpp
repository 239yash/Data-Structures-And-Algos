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
        } else {
            representative[rootU] = rootV;
            size[rootV] += size[rootU];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        for (auto x : equations) {
            if (x[1] == '=') {
                uf.combine(x[0] - 'a', x[3] - 'a');
            }
        }
        
        for (auto x : equations) {
            if (x[1] == '!' && uf.find(x[0] - 'a') == uf.find(x[3] - 'a'))
                return false;
        }
        return true;
    }
};




// You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

// Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

// Example 1:

// Input: equations = ["a==b","b!=a"]
// Output: false
// Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
// There is no way to assign the variables to satisfy both equations.
// Example 2:

// Input: equations = ["b==a","a==b"]
// Output: true
// Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
