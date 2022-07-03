class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<0) return -1;
        if(amount==0) return 0;
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        
        for(int i=1;i<=amount;i++){
            int res=INT_MAX;
            for(int j=0;j<coins.size();j++) {
                if(coins[j]<=i && dp[i-coins[j]]!=-1) {
                    res = min(res, dp[i-coins[j]]+1);
                }
            }
            dp[i] = (res==INT_MAX)?-1:res;
        }
        
        return dp[amount];
    }
};