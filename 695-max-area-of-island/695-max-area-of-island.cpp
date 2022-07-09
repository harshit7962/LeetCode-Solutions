class Solution {
public:
    int bfs(vector<vector<int>>&grid, int row, int col) {
        int area = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 0;
        
        while(!q.empty()) {
            int curr_row = q.front().first, curr_col = q.front().second;
            q.pop();
            area++;
            
            //Moving UP
            if(curr_row-1>=0 && grid[curr_row-1][curr_col]==1) {
                q.push({curr_row-1, curr_col});
                grid[curr_row-1][curr_col]=0;
            }
            
            //Moving Down
            if(curr_row+1<grid.size() && grid[curr_row+1][curr_col]==1) {
                grid[curr_row+1][curr_col]=0;
                q.push({curr_row+1, curr_col});
            }
            
            //Moving Left
            if(curr_col-1>=0 && grid[curr_row][curr_col-1]==1) {
                q.push({curr_row, curr_col-1});
                grid[curr_row][curr_col-1]=0;
            }
            
            //Moving Right
            if(curr_col+1<grid[0].size() && grid[curr_row][curr_col+1]==1) {
                grid[curr_row][curr_col+1]=0;
                q.push({curr_row, curr_col+1});
            }
        }
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == 1) {
                    int x = bfs(grid, i, j);
                    res = max(res, x);
                }
            }
        }
        
        
        return res;
    }
};