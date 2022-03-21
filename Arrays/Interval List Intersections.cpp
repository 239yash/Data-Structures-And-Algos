class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        if(f.size() == 0 || s.size() == 0) return {};
        std::vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        std::vector<int> temp(2);
        while(i < f.size() && j < s.size()) {
            temp[0] = max(s[j][0], f[i][0]);
            temp[1] = min(s[j][1], f[i][1]);
            if(temp[0] <= temp[1])
                ans.push_back(temp);
            if(f[i][1] <= s[j][1]) ++i;
            else ++j;
        }
        return ans;
    }
};
