class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1));
        
        for(int i=0;i<n;i++) {
            for(int j=1;j<=amount;j++) {
                int prev=(j-coins[i]>=0)?dp[i][j-coins[i]]:0, up=(i==0)?0:dp[i-1][j];
                dp[i][j] = prev+up;
            }
        }
        
        return dp[n-1][amount];
    }
};