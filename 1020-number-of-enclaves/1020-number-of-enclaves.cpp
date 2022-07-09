class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if(grid[i][j]==0) return 0;
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()) return -1;
        
        grid[i][j] = 0;
        
        int top = dfs(grid, i-1, j);
        int bottom = dfs(grid, i+1, j);
        int left = dfs(grid, i, j-1);
        int right = dfs(grid, i, j+1);
        
        if(top==-1 || bottom==-1 || left==-1 || right==-1) return -1;
        
        return 1+top+bottom+left+right;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int res=0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    int x = dfs(grid, i, j);
                    if(x!=-1) res+=x;
                }
            }
        }
        
        return res;
    }
};