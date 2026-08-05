class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        if (grid[0][0] == 1 || grid[n][n] == 1) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int level = 1;
        while (!q.empty()) {
            int curr_level_sz = q.size();
            for (int i = 0; i < curr_level_sz; ++i) {
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                if (r == n && c == n) return level;
                if (r > 0) {
                    // 左
                    if (grid[r - 1][c] == 0) {
                        grid[r - 1][c] = 1;
                        q.push({r - 1, c});
                    }
                    // 左上
                    if (c > 0 && grid[r - 1][c - 1] == 0) {
                        grid[r - 1][c - 1] = 1;
                        q.push({r - 1, c - 1});
                    }
                    // 左下
                    if (c < n && grid[r - 1][c + 1] == 0) {
                        grid[r - 1][c + 1] = 1;
                        q.push({r - 1, c + 1});
                    }
                }
                if (r < n) {
                    // 右
                    if (grid[r + 1][c] == 0) {
                        grid[r + 1][c] = 1;
                        q.push({r + 1, c});
                    }
                    // 右上
                    if (c > 0 && grid[r + 1][c - 1] == 0) {
                        grid[r + 1][c - 1] = 1;
                        q.push({r + 1, c - 1});
                    }
                    // 右下
                    if (c < n && grid[r + 1][c + 1] == 0) {
                        grid[r + 1][c + 1] = 1;
                        q.push({r + 1, c + 1});
                    }
                }
                if (c > 0) {
                    // 上
                    if (grid[r][c - 1] == 0) {
                        grid[r][c - 1] = 1;
                        q.push({r, c - 1});
                    }
                }
                if (c < n) {
                    // 下
                    if (grid[r][c + 1] == 0) {
                        grid[r][c + 1] = 1;
                        q.push({r, c + 1});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};