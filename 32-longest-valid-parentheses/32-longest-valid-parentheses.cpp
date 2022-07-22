class Solution {
public:
    int longestValidParentheses(string s) {
        //We will find the longest valid parentheses ending with index i for each index...
        int n = s.size(), ans = 0;
        vector<int> dp(n, 0);
        
        for(int i=1;i<n;i++) {
            //We know a valid parentheses will end only with closing bracket...
            if(s[i] == ')') {
                //If the prev character is opening bracket we can get the current longest by adding 2 to previous' previous value...
                if(s[i-1]=='(') {
                    dp[i] = 2 + (i==1?0:dp[i-2]);
                } else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(') {
                    //If prev character is not opening bracket, then we can check it with the previous character's last valid bracket, using dp array's indexing...
                    dp[i] = 2 + (i-dp[i-1]-1>0?dp[i-dp[i-1]-2]:0) + dp[i-1];
                }
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};