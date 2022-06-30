class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n = s.size();
        if(n==1) return 1;
        
        vector<int> dp(n, 0);
        
        dp[0]=1;
        if(s[1]=='0' && s[0]>'2') return 0;
        if(s[1]=='0' || s[0]>'2' || (s[0]=='2'&&s[1]>'6')) dp[1] = 1;
        else dp[1] = 2;
        
        for(int i=2;i<n;i++) {
            char prev = s[i-1], curr = s[i];
            
            if(prev=='0' && curr=='0') return 0;
            else if(prev=='0') dp[i] = dp[i-1];
            else if(curr=='0') {
                if(prev>'2') return 0;
                dp[i] = dp[i-2];
            } else {
                if(prev>'2') dp[i]=dp[i-1];
                else if(prev=='2' && curr>'6') dp[i] = dp[i-1];
                else dp[i] = dp[i-1]+dp[i-2];
            }
        }
        
        return dp[n-1];
    }
};