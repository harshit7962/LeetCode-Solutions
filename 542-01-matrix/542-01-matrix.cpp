class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0) q.push({{i, j}, 0});
                else grid[i][j] = -1;
            }
        }
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            
            q.pop();
            
            if(row!=0 && grid[row-1][col]==-1) {
                grid[row-1][col] = dis+1;
                q.push({{row-1, col}, dis+1});
            }
            
            if(col!=0 && grid[row][col-1]==-1) {
                grid[row][col-1] = dis+1;
                q.push({{row, col-1}, dis+1});
            }
            
            if(row<m-1 && grid[row+1][col]==-1) {
                grid[row+1][col] = dis+1;
                q.push({{row+1, col}, dis+1});
            }
            
            if(col<n-1 && grid[row][col+1]==-1) {
                grid[row][col+1] = dis+1;
                q.push({{row, col+1}, dis+1});
            }
        }
        
        return grid;
    }
};