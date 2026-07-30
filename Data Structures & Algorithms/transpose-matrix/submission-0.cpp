class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int i = matrix.size();
        int j = matrix[0].size();
        vector<vector<int>> ans(j, vector<int>(i,0));
        for (int ii = 0; ii < i; ii++) {
            for (int jj= 0; jj < j; jj++) {
                ans[jj][ii] = matrix[ii][jj];
            }
        }
        return ans;
    }
};