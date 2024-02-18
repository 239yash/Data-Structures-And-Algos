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
        if (rootU != rootV) {
            representative[rootU] = rootV;
            size[rootV] += size[rootU];
        }       
    }

    int getLargestSize() {
        int maxSize = 0;
        for (int i = 0; i < representative.size(); i++) {
            if (representative[i] == i) {
                maxSize = max(maxSize, size[i]);
            }
        }
        return maxSize;
    }
};


class Solution {
    public: 
    int longestConsecutive(vector<int>& nums) {
        UnionFind uf(nums.size());
        std::unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) 
                continue;
            if (mp.find(nums[i] - 1) != mp.end())
                uf.combine(i, mp[nums[i] - 1]);
            if (mp.find(nums[i] + 1) != mp.end())
                uf.combine(i, mp[nums[i] + 1]);
            
            mp[nums[i]] = i;
        }
        
        return uf.getLargestSize();
    }
};

