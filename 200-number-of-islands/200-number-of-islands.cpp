class Solution {
public:
    void dfs(vector<vector<char>>&grid, int row, int col) {
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]=='0') return;
        grid[row][col] = '0';
        
        //Moving up
        dfs(grid, row-1, col);
        
        //Moving Down
        dfs(grid, row+1, col);
        
        //Moving left
        dfs(grid, row, col-1);
        
        //Moving right
        dfs(grid, row, col+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]=='1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        
        return res;
    }
};