class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 所以這有兩個要判斷一個是有沒有連續 一個是bfs擴散的速度
        int ans = 0;
        
        // find all 2 
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        // traserve
        for (int i = 0; i < row; ++i) {
            for (int j = 0 ; j < col; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            int curr_level = q.size();
            bool rot_pass = false;
            for (int i = 0; i < curr_level; ++i) {
                auto curr = q.front();
                q.pop();
                int curr_r = curr.first;
                int curr_c = curr.second;
                if (curr_r > 0) {
                    if (grid[curr_r - 1][curr_c] == 1) {
                        grid[curr_r - 1][curr_c] = 2;
                        rot_pass = true;
                        q.push({curr_r - 1, curr_c});
                    }
                }
                if (curr_r < row - 1) {
                    if (grid[curr_r + 1][curr_c] == 1) {
                        grid[curr_r + 1][curr_c] = 2;
                        rot_pass = true;
                        q.push({curr_r + 1, curr_c});
                    }
                }
                if (curr_c > 0) {
                    if (grid[curr_r][curr_c - 1] == 1) {
                        grid[curr_r][curr_c - 1] = 2;
                        rot_pass = true;
                        q.push({curr_r, curr_c - 1});
                    }
                }
                if (curr_c < col - 1) {
                    if (grid[curr_r][curr_c + 1] == 1) {
                        grid[curr_r][curr_c + 1] = 2;
                        rot_pass = true;
                        q.push({curr_r, curr_c + 1});
                    }
                }
            }
            for (int i = 0; i < row; ++i) {
                for (int j = 0 ; j < col; ++j) {
                    cout << grid[i][j] << " ";
                    
                }
                cout << endl;
            }
            if (rot_pass) ans++;
            cout << "ans: " << ans << endl;  
        }

            

        
        for (int i = 0; i < row; ++i) {
            for (int j = 0 ; j < col; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
