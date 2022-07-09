class Solution {
public:
    
    bool dfs(vector<vector<int>> &grid, int row, int col) {
        if(grid[row][col] == 1) return true;
        if(row==0 || col==0 || row==grid.size()-1 || col==grid[0].size()-1) return false;
        
        grid[row][col]=1;
        
        bool flag1 = dfs(grid, row-1, col);
        bool flag2 = dfs(grid, row+1, col);
        bool flag3 = dfs(grid, row, col-1);
        bool flag4 = dfs(grid, row, col+1);
        
        return (flag1 && flag2 && flag3 && flag4);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int res=0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==0) {
                    bool f = dfs(grid, i, j);
                    if(f) res++;
                }
            }
        }
        
        
        return res;
    }
};