class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, queue<pair<pair<int, int>, int>> &q) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size() || grid[i][j]!=1) return;
        
        grid[i][j] = 2;
        q.push({{i, j}, 0});
        
        dfs(grid, i-1, j, q);
        dfs(grid, i, j-1, q);
        dfs(grid, i+1, j, q);
        dfs(grid, i, j+1, q);
    }
    
    int simulBFS(vector<vector<int>> grid, queue<pair<pair<int, int>, int>> &q) {
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int curr_len = q.front().second;
            
            q.pop();            
            
            //Moving up
            if(i!=0 && grid[i-1][j]!=2) {
                if(grid[i-1][j]==1) return curr_len+1;
                q.push({{i-1, j}, curr_len+1});
                grid[i-1][j]=2;
            }
            
            //Moving Down
            if(i!=grid.size()-1 && grid[i+1][j]!=2) {
                if(grid[i+1][j]==1) return curr_len+1;
                q.push({{i+1, j}, curr_len+1});
                grid[i+1][j]=2;
            }
            
            //Moving Left
            if(j!=0 && grid[i][j-1]!=2) {
                if(grid[i][j-1]==1) return curr_len+1;
                q.push({{i, j-1}, curr_len+1});
                grid[i][j-1]=2;
            }
            
            //Moving Right
            if(j!=grid.size()-1 && grid[i][j+1]!=2) {
                if(grid[i][j+1]==1) return curr_len+1;
                q.push({{i, j+1}, curr_len+1});
                grid[i][j+1]=2;
            }
        }
        
        return -1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<pair<int, int>, int>> q;
        //We will mark any one cluster of islands as 2 in our grid, and this can be done either using dfs traversal or bfs traversal
        bool flag=false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    dfs(grid, i, j, q);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        
        //For each cell marked as 2, we find the nearest 1 to it, and store it in our result...
        return simulBFS(grid, q)-1;
    }
};