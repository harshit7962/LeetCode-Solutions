class Solution {
public:    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0]=1;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++){
                if(dp[i][j]==1 || grid[i][j]==1) continue;
                else {
                    dp[i][j] = ((i>0)?dp[i-1][j]:0) + ((j>0)?dp[i][j-1]:0);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};