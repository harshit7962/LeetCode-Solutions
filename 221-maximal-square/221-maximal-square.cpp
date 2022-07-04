class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res=0, m=matrix.size(), n=matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == '1') {
                    int left = (j==0)?0:dp[i][j-1];
                    int up = (i==0)?0:dp[i-1][j];
                    int diagonal = (i==0 || j==0)?0:dp[i-1][j-1];
                    
                    dp[i][j] = 1 + min(left, min(up, diagonal));
                    
                    res = max(res, dp[i][j]);
                }
            }
        }
        
        return res*res;
    }
};