class Solution {
public:
    void traverse_island(vector<vector<char>>&grid, int i, int j) {
        if (grid[i][j] == '0') return;
        else grid[i][j] = '0';

        if (i - 1 >= 0) traverse_island(grid, i - 1, j);
        if (i + 1 < grid.size()) traverse_island(grid, i + 1, j);
        if (j - 1 >= 0) traverse_island(grid, i, j - 1);
        if (j + 1 < grid[0].size()) traverse_island(grid, i, j + 1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int col = grid[0].size();
        int row = grid.size();
        int ans = 0;
        for(int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    traverse_island(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
