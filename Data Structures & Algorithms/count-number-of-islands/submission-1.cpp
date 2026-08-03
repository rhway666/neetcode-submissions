class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r > grid.size() - 1 || c < 0 || c > grid[0].size() - 1 ) return ;
        if (grid[r][c] == '0') return ;
        grid[r][c] = '0';
        dfs(grid, r - 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r + 1, c);
        dfs(grid, r, c + 1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int col = grid[0].size();
        int row = grid.size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
