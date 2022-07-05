class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0) return 0;
        vector<int> dp(s.size(), 0);
        int ans = 0;
        
        for(int i=1;i<s.size();i++) {
            if(s[i]==')') {
                if(s[i-1]=='(') {
                    dp[i] = (i-2>=0)?dp[i-2]+2:2;
                } else if(i-1-dp[i-1]>=0 && s[i-dp[i-1]-1]=='(') {
                    dp[i] = dp[i-1] + (i - dp[i-1]>=2?dp[i-dp[i-1]-2]:0)+2;
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};