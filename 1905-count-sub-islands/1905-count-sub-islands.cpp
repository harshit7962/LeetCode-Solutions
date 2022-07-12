class Solution {
public:
    bool dfs(vector<vector<int>>&grid, int i, int j) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return true;
        if(grid[i][j] == 1) return false;
        
        grid[i][j] = 0;
        
        bool flag1 = dfs(grid, i-1, j);
        bool flag2 = dfs(grid, i+1, j);
        bool flag3 = dfs(grid, i, j-1);
        bool flag4 = dfs(grid, i, j+1);
        
        return flag1 && flag2 && flag3 && flag4;        
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid2[i][j]==1 && grid1[i][j]==1) grid2[i][j] = 2;
            }
        }
        
        int res = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid2[i][j]==2) {
                    if(dfs(grid2, i, j)) res++;
                }
            }
        }
        
        return res;
    }
};