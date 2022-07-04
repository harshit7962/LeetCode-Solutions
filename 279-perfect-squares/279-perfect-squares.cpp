class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2;i<=n;i++) {
            if((int)sqrt(i)*(int)sqrt(i)==i) dp[i]=1;
            else {
                for(int j=1;j<=sqrt(i);j++) {
                    dp[i] = min(dp[i], dp[j*j]+dp[i-j*j]);
                }
            }
        }
        
        return dp[n];
    }
};