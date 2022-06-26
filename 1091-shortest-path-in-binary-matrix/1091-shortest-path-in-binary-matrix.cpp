class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int count=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        int n = grid.size();

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        while(!q.empty()) {
            count++;
            int c = q.size();
            for(int x=0;x<c;x++) {
                int i = q.front().first;
                int j = q.front().second;
                if(i==n-1 && j==n-1) return count;
                q.pop();
                
                if(i!=0 && grid[i-1][j]==0 && !visited[i-1][j]) {
                    visited[i-1][j]= true;
                    q.push({i-1, j});
                }
                if(i!=n-1 && grid[i+1][j]==0 && !visited[i+1][j] ) {
                    visited[i+1][j]= true;
                    q.push({i+1, j});
                }
                if(j!=0 && grid[i][j-1]==0 && !visited[i][j-1]) {
                    visited[i][j-1]= true;
                    q.push({i, j-1});
                }
                if(j!=n-1 && grid[i][j+1]==0 && !visited[i][j+1]) {
                    visited[i][j+1]= true;
                    q.push({i, j+1});
                }
                if(i!=0 && j!=0 && grid[i-1][j-1]==0 && !visited[i-1][j-1]) {
                    visited[i-1][j-1]= true;
                    q.push({i-1, j-1});
                }
                if(i!=n-1 && j!=0 && grid[i+1][j-1]==0 && !visited[i+1][j-1]) {
                    visited[i+1][j-1]= true;
                    q.push({i+1, j-1});
                }
                if(j!=n-1 && i!=0 && grid[i-1][j+1]==0 && !visited[i-1][j+1]) {
                    visited[i-1][j+1]= true;
                    q.push({i-1, j+1});
                }
                if(i!=n-1 && j!=n-1 && grid[i+1][j+1]==0 && !visited[i+1][j+1]) {
                    visited[i+1][j+1]= true;
                    q.push({i+1, j+1});
                }
            }
        }
        
        return -1;
    }
};