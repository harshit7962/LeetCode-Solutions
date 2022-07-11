class Solution {
public:
    void dfs(vector<vector<int>>&grid, vector<vector<bool>>&visited, int row, int col) {
        if(visited[row][col]) return;
        visited[row][col] = true;
        
        if(row!=0 && grid[row][col] <= grid[row-1][col]) dfs(grid, visited, row-1, col);
        if(col!=0 && grid[row][col] <= grid[row][col-1]) dfs(grid, visited, row, col-1);
        if(row!=grid.size()-1 && grid[row][col] <= grid[row+1][col]) dfs(grid, visited, row+1, col);
        if(col!=grid[0].size()-1 && grid[row][col] <= grid[row][col+1]) dfs(grid, visited, row, col+1);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac_vis(m, vector<bool>(n, false)), atl_vis(m, vector<bool>(n, false));
        
        for(int row=0;row<m;row++) {
            if(!pac_vis[row][0]) {dfs(heights, pac_vis, row, 0);}
            if(!atl_vis[row][n-1]) {dfs(heights, atl_vis, row, n-1);}
        }
        
        for(int col=0;col<n;col++) {
            if(!pac_vis[0][col]) {dfs(heights, pac_vis, 0, col);}
            if(!atl_vis[m-1][col]) {dfs(heights, atl_vis, m-1, col);}
        }
        
        vector<vector<int>> res;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pac_vis[i][j] && atl_vis[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
};