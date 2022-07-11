class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int count_fresh = 0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) count_fresh++;
                if(grid[i][j] == 2) q.push({{i, j}, 0});
            }
        }
        
        int curr_time=0;
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            curr_time = q.front().second;
            
            q.pop();
            
            //Moving up
            if(row!=0 && grid[row-1][col]==1) {
                count_fresh--;
                grid[row-1][col] = 2;
                q.push({{row-1, col}, curr_time+1});
            }
            
            //Moving Down
            if(row!=grid.size()-1 && grid[row+1][col]==1) {
                count_fresh--;
                grid[row+1][col] = 2;
                q.push({{row+1, col}, curr_time+1});
            }
            
            //Moving Left
            if(col!=0 && grid[row][col-1]==1) {
                count_fresh--;
                grid[row][col-1] = 2;
                q.push({{row, col-1}, curr_time+1});
            }
            
            //Moving Right
            if(col!=grid[0].size()-1 && grid[row][col+1]==1) {
                count_fresh--;
                grid[row][col+1] = 2;
                q.push({{row, col+1}, curr_time+1});
            }
        }
        
        if(count_fresh!=0) return -1;
        return curr_time;
    }
};