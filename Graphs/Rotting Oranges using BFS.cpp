class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::queue<pair<int, int>> q;
        int count = 0;
        for(int i = 0; i < grid.size(); ++i) 
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2)
                    q.push(make_pair(i, j));
                if(grid[i][j] == 1)
                    ++count;
            }
        if(count == 0) return 0;
        
        q.push(make_pair(-1, -1));
        int ans = 0;
        while(q.size() > 1) {
            pair<int, int> curr = q.front();
            q.pop();
            if(curr.first == -1 && curr.second == -1){
                ++ans;
                q.push(make_pair(-1, -1));
                continue;
            }
            
            int i = curr.first;
            int j = curr.second;
            if(i - 1 >= 0 && grid[i - 1][j] == 1) {
                q.push(make_pair(i - 1, j));
                grid[i - 1][j] = 2;
                --count;
            }
            if(j - 1 >= 0 && grid[i][j - 1] == 1) {
                q.push(make_pair(i, j - 1));
                grid[i][j - 1] = 2;
                --count;
            }
            if(i + 1 < grid.size() && grid[i + 1][j] == 1) {
                q.push(make_pair(i + 1, j));
                grid[i + 1][j] = 2;
                --count;
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
                q.push(make_pair(i, j + 1));
                grid[i][j + 1] = 2;
                --count;
            }
        }
        
        if(count != 0) return -1;
        return ans;
    }
};

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4


// Example 2:
// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.


// Example 3:
// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
