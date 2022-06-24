class Solution {
public:
    
    bool isSub(vector<vector<int>> &grid, int i, int j) {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0) return true;
        if(grid[i][j]==-1) return false;
        
        grid[i][j]=0;
        
        bool flag1 = isSub(grid, i+1, j);
        bool flag2 = isSub(grid, i-1, j);
        bool flag3 = isSub(grid, i, j+1);
        bool flag4 = isSub(grid, i, j-1);
        
        if(flag1&&flag2&&flag3&&flag4) return true;
        grid[i][j]=-1;
        return false;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(), n=grid1[0].size();
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid1[i][j]==1 && grid2[i][j]==1) grid1[i][j]=2;
                else if(grid2[i][j]==1) grid1[i][j]=-1;
                else grid1[i][j]=0;
            }
        }
        
        int res=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid1[i][j]==2 && isSub(grid1, i, j)) {
                    res++;
                }
            }
        }
        
        return res;
    }
};