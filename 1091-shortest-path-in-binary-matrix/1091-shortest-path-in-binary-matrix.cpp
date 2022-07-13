class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0,0}, 1});
        
        vector<int> directx = {-1,1,0,0,-1,-1,1,1}, directy = {0,0,-1,1,-1,1,-1,1};
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            
            q.pop();
            
            if(row == n-1 && col == n-1) return dis;
            
            for(int i=0;i<8;i++) {
                int newrow = row+directx[i], newcol = col+directy[i];
                if(newrow>=0 && newcol>=0 && newrow<n && newcol<n && grid[newrow][newcol]!=1) {
                    grid[newrow][newcol] = 1;
                    q.push({{newrow, newcol}, dis+1});
                }
            }
        }
        
        return -1;
    }
};