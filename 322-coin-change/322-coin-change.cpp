class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n = coins.size();
        
        vector<vector<long>> dp(n+1, vector<long>(amount+1,INT_MAX));
        
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=amount;j++) {
                dp[i][j] = dp[i-1][j];
                if(j-coins[i-1]>=0) {
                    dp[i][j] = min(dp[i][j], 1+dp[i][j-coins[i-1]]);
                }
                
            }
        }
        
        return (dp[n][amount]==INT_MAX)?-1:dp[n][amount];
    }
};