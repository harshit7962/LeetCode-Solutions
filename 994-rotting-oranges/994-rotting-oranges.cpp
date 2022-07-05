class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        
        int num_fresh = 0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2) {
                    q.push({{i,j},0});
                } else if(grid[i][j] == 1) num_fresh++;
                
            }
        }
        
        int res=0;
        while(!q.empty()) {
            int curr_row = q.front().first.first;
            int curr_col = q.front().first.second;
            int curr_tim = q.front().second;
            
            res = curr_tim;
            
            q.pop();
            
            
            //Travelling UP
            if(curr_row!=0 && grid[curr_row-1][curr_col]==1) {
                num_fresh--;
                q.push({{curr_row-1, curr_col}, curr_tim+1});
                grid[curr_row-1][curr_col] = 2;
            }
            
            //Travelling DOWN
            if(curr_row!=m-1 && grid[curr_row+1][curr_col]==1) {
                num_fresh--;
                q.push({{curr_row+1, curr_col}, curr_tim+1});
                grid[curr_row+1][curr_col] = 2;
            }
            
            //Travelling LEFT
            if(curr_col!=0 && grid[curr_row][curr_col-1]==1) {
                num_fresh--;
                q.push({{curr_row, curr_col-1}, curr_tim+1});
                grid[curr_row][curr_col-1] = 2;
            }
            
            //Travelling RIGHT
            if(curr_col!=n-1 && grid[curr_row][curr_col+1]==1) {
                num_fresh--;
                q.push({{curr_row, curr_col+1}, curr_tim+1});
                grid[curr_row][curr_col+1] = 2;
            }
            
        }
        
        return (num_fresh==0)?res:-1;
    }
};