class Solution {
public:
    void dfs(vector<vector<int>> &grid, queue<pair<pair<int, int>, int>>&q, int row, int col, int n) {
        if(row<0 || col<0 || row==n || col==n || grid[row][col]!=1) return;
        
        q.push({{row, col}, 0});
        grid[row][col] = -1;
        
        dfs(grid, q, row-1, col, n);
        dfs(grid, q, row, col-1, n);
        dfs(grid, q, row+1, col, n);
        dfs(grid, q, row, col+1, n);        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<pair<int, int>, int>> q;
        
        bool flag = false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, q, i, j, n);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        
        //Initiating Simultaneous BFS
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            
            q.pop();
            
            if(row!=0 && grid[row-1][col]!=-1) {
                if(grid[row-1][col]==1) return dis;
                grid[row-1][col] = -1;
                q.push({{row-1, col}, dis+1});
            }
            
            if(col!=0 && grid[row][col-1]!=-1) {
                if(grid[row][col-1]==1) return dis;
                grid[row][col-1] = -1;
                q.push({{row, col-1}, dis+1});
            }
            
            if(row!=n-1 && grid[row+1][col]!=-1) {
                if(grid[row+1][col]==1) return dis;
                grid[row+1][col] = -1;
                q.push({{row+1, col}, dis+1});
            }
            
            if(col!=n-1 && grid[row][col+1]!=-1) {
                if(grid[row][col+1]==1) return dis;
                grid[row][col+1] = -1;
                q.push({{row, col+1}, dis+1});
            }
        }
        
        return -1;
    }
};