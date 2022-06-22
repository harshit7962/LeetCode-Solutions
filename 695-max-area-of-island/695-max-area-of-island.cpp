class Solution {
public:
    int bfs(vector<vector<int>> &grid, int row, int col) {
        if(row<0||col<0||row>=grid.size()||col>=grid[0].size()||grid[row][col]==0) return 0;
        grid[row][col]=0;
        return 1+bfs(grid,row-1,col)+bfs(grid,row+1,col)+bfs(grid,row,col-1)+bfs(grid,row,col+1);
    } 
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), res=0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                res = max(res, bfs(grid, i, j));
            }
        }
        
        return res;
    }
};