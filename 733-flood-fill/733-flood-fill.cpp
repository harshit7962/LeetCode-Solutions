class Solution {
public:
    void dfs(vector<vector<int>> &image, int row, int col, int color, int par_col) {
        if(row<0 || col<0 || row>=image.size() || col>=image[0].size() || image[row][col]!=par_col) return;
        
        image[row][col] = color;
        
        //Moving Down
        dfs(image, row+1, col, color, par_col);
        
        // Moving Up
        dfs(image, row-1, col, color, par_col);
        
        //Moving left
        dfs(image, row, col-1, color, par_col);
        
        //Moving right
        dfs(image, row, col+1, color, par_col);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        
        dfs(image, sr, sc, color, image[sr][sc]);
        
        return image;
    }
};