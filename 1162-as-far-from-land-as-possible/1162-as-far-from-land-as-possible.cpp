class Solution {
public:
    int simulBFS(queue<pair<int,int>> &q, vector<vector<int>> &grid) {
        int count=-1;
        while(!q.empty()) {
            int c = q.size();
            count++;
            for(int i=0;i<c;i++) {
                pair<int, int> p = q.front();
                q.pop();
                
                if(p.first-1>=0 && grid[p.first-1][p.second]==0) {
                    q.push({p.first-1, p.second});
                    grid[p.first-1][p.second]=1;
                }
                if(p.first+1<grid.size() && grid[p.first+1][p.second]==0) {
                    q.push({p.first+1, p.second});
                    grid[p.first+1][p.second]=1;
                }
                if(p.second-1>=0 && grid[p.first][p.second-1]==0) {
                    q.push({p.first, p.second-1});
                    grid[p.first][p.second-1]=1;
                }
                if(p.second+1<grid.size() && grid[p.first][p.second+1]==0) {
                    q.push({p.first, p.second+1});
                    grid[p.first][p.second+1]=1;
                }
            }
        }
        
        return count;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) {
                    q.push({i, j});
                }
            }
        }
        
        int res = simulBFS(q, grid);
        
        return res==0?-1:res;
    }
};