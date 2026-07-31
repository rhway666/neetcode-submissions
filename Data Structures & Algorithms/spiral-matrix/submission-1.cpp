class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int b_l = 0;
        int b_r = matrix[0].size() - 1;
        int b_u = 0;
        int b_d = matrix.size() - 1;
        // odd -> last iter on same , even -> last b_l + 1 = b_r
        while (b_l <= b_r && b_u <= b_d) {
            // right iter
            for (int i = b_l; i <= b_r; ++i) {
                ans.push_back(matrix[b_u][i]);
            }
            b_u++;
            // down iter
            for (int i = b_u; i <= b_d; ++i) {
                ans.push_back(matrix[i][b_r]);
            }
            b_r--;
            // left iter
            if (b_u <= b_d) {
                for (int i = b_r; i >= b_l; --i) {
                    ans.push_back(matrix[b_d][i]);
                }
                b_d--;
            }
            
            // right iter
            if (b_l <= b_r) {
                for (int i = b_d; i >= b_u; --i) {
                    ans.push_back(matrix[i][b_l]);
                }
                b_l++;
            }
        }

        return ans;
    }
};
