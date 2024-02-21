class Solution {
public:
    int count = 0;
    int dp[302][302];
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp, -1, sizeof(dp));
        func(matrix, 0, 0);
        return count * count;
    }
    
    int func(vector<vector<char>>& matrix, int i, int j) {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int r = func(matrix, i, j + 1);
        int d = func(matrix, i + 1, j);
        int di = func(matrix, i + 1, j + 1);
        
        int temp = 0;
        if (matrix[i][j] == '1') {
            temp = 1 + min(r, min(d, di));
            count = max(count, temp);
        }
        return dp[i][j] = temp;
    }
};
