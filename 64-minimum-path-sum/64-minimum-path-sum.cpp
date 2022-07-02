class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0 && j==0) continue;
                int left = (j==0)?INT_MAX:grid[i][j-1];
                int up = (i==0)?INT_MAX:grid[i-1][j];
                
                grid[i][j] += min(left, up);
            }
        }
        
        return grid[m-1][n-1];
    }
};