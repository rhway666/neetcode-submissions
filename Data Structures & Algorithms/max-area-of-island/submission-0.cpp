class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int& ans) {
        if (r < 0 || r > grid.size() - 1 || c < 0 || c > grid[0].size() - 1 ) return ;
        if (grid[r][c] == 0) return;
        grid[r][c] = 0;
        ans++;
        dfs(grid, r - 1, c, ans);
        dfs(grid, r, c - 1, ans);
        dfs(grid, r + 1, c, ans);
        dfs(grid, r, c + 1, ans);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int col = grid[0].size();
        int row = grid.size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    int curr = 0;
                    dfs(grid, i, j, curr);
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};
