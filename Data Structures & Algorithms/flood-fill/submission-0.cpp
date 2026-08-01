class Solution {
public:
    void dfs(vector<vector<int>>& image, int curr_r, int curr_c, int color,int new_color) {
        int row = image.size();
        int col = image[0].size();
        if (curr_r > row - 1 || curr_r < 0 || curr_c > col - 1 || curr_c < 0) return;
        if (image[curr_r][curr_c] != new_color) return;
        image[curr_r][curr_c] = color;

        dfs(image, curr_r - 1, curr_c, color, new_color); 
        dfs(image, curr_r + 1, curr_c, color, new_color); 
        dfs(image, curr_r, curr_c - 1, color, new_color); 
        dfs(image, curr_r, curr_c + 1, color, new_color);
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int new_color = image[sr][sc];
        if(new_color == color) return image;
        dfs(image, sr, sc, color, new_color);
        return image;
    }
};