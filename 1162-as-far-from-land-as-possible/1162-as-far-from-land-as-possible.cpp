class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid.size();j++) {
                if(grid[i][j]==1) {
                    q.push({{i, j}, 0});
                }
            }
        }
        
        int res = -1;
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            
            q.pop();
            
            //Moving up
            if(row!=0 && grid[row-1][col]==0) {
                grid[row-1][col] = 1;
                res = dis+1;
                q.push({{row-1, col}, dis+1});
            }
            
            //Moving Down
            if(row!=grid.size()-1 && grid[row+1][col]==0) {
                grid[row+1][col] = 1;
                res = dis+1;
                q.push({{row+1, col}, dis+1});
            }
            
            //Moving Left
            if(col!=0 && grid[row][col-1]==0) {
                grid[row][col-1] = 1;
                res = dis+1;
                q.push({{row, col-1}, dis+1});
            }
            
            //Moving Right
            if(col!=grid.size()-1 && grid[row][col+1]==0) {
                grid[row][col+1] = 1;
                res = dis+1;
                q.push({{row, col+1}, dis+1});
            }
        }
                
        return res;
    }
};