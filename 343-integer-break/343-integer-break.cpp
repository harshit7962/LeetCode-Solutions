class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++) {
            if(i!=n) dp[i]=i;
            for(int j=1;j<i;j++) {
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
            }
        }
        
        return dp[n];
    }
};