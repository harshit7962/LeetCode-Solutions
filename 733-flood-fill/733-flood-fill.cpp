class Solution {
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int prev) {
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()) return;
        
        image[sr][sc] = color;
        
        if(sr!=0 && image[sr-1][sc]==prev) dfs(image, sr-1, sc, color, prev);
        if(sc!=0 && image[sr][sc-1]==prev) dfs(image, sr, sc-1, color, prev);
        if(sr<image.size()-1 && image[sr+1][sc]==prev) dfs(image, sr+1, sc, color, prev);
        if(sc<image[0].size()-1 && image[sr][sc+1]==prev) dfs(image, sr,sc+1, color, prev);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color) {
            dfs(image, sr, sc, color, image[sr][sc]);
        }
        
        return image;
    }
};