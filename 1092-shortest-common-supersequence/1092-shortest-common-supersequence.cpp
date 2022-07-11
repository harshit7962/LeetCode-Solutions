class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int m = a.size(), n = b.size();
        
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(a[i-1] == b[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        string lcs = "";
        
        int i=m, j=n;
        
        while(i>0 && j>0) {
            if(a[i-1] == b[j-1]) {
                lcs = a[i-1] + lcs;
                i--;
                j--;
            } else {
                if(dp[i][j-1]>dp[i-1][j]) j--;
                else i--;
            }
        }
        
        int ind=0;
        i = j = 0;
        string res = "";
        while(i<m && j<n && ind<lcs.size()) {
            if(a[i] == lcs[ind] && b[j] == lcs[ind]) {
                res+=lcs[ind];
                ind++;
                i++;
                j++;
            } else if(a[i]!=lcs[ind]) {
                res+=a[i++];
            } else if(b[j]!=lcs[ind]) {
                res+=b[j++];
            }
        }
        
        if(ind==lcs.size()) {
            res+=a.substr(i);
            res+=b.substr(j);
        }
        
        return res;
    }
};