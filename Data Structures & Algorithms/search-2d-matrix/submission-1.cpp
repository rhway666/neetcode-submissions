class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size();
        int row = matrix.size();
        int l = -1;
        int r = col * row;
        while (l + 1 != r) {
            int m = (l + r) / 2;
            int curr_col = m % col, curr_row = m/ col;
            if (matrix[curr_row][curr_col] == target) {
                return true;
            } else if (matrix[curr_row][curr_col] < target) {
                l = m;
            } else {
                r = m;
            }
        }
        return false;
    }
};
