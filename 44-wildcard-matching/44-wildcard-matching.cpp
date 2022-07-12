class Solution {
public:
    bool isMatch(string p, string s) {
        int m = s.size(), n = p.size();
        
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0] = true;
        
        // for(int i=1;i<=m;i++) if(s[i-1]=='*') dp[i][0] = true;
        
        for(int i=1;i<=m;i++) {
            if(s[i-1]=='*' && dp[i-1][0]) dp[i][0] = true;
            for(int j=1;j<=n;j++) {
                if(s[i-1] == p[j-1] || s[i-1]=='?') dp[i][j] = dp[i-1][j-1];
                else {
                    if(s[i-1]=='*') {
                        int k=j;
                        while(k>=0) {
                            if(dp[i-1][k]) {dp[i][j] = true; break;}
                            k--;
                        }
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};