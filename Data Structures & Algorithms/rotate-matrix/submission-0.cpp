class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
        1   2  3  4 
        5   6  7  8
        9  10 11 12
        13 14 15 16
        rot:
        13 9  5  1 
        14 10 6  2
        15 11 7  3
        16 12 8  4

        (0,2)->(2,3)
        (1,2)->(2,2)
        (2,2)->(2,1)
        (3,4)->(2,0) 

        (1,0)->(0,2)
        (1,1)->(1,2)
        (1,2)->(2,2)
        (1,3)->(3,2)
        */
        // org[i][j] ->rot[j][n - i - 1]
        int n = matrix.size();

        // in-place org[i][j] -> trans[j][i] -> 左右reverse 
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n/2; ++j) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
        return ;
    }
};
