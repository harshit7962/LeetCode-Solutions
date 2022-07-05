class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(strs.size(), -1)));
        return findMax(strs, m, n, 0, dp);
    }
    
    int findMax(vector<string>&strs, int m, int n, int ind, vector<vector<vector<int>>> &dp) {
        if(ind == strs.size()) return 0;
        if(dp[m][n][ind]!=-1) return dp[m][n][ind];
        
        int num_zeros = zeros(strs[ind]);
        int num_ones = strs[ind].size()-num_zeros;
        
        if(num_zeros<=m && num_ones<=n) return dp[m][n][ind] = max(1+findMax(strs, m-num_zeros, n-num_ones, ind+1, dp),
                                                  findMax(strs, m, n, ind+1, dp));
       
        return dp[m][n][ind] = findMax(strs, m, n, ind+1, dp);
    }
    
    int zeros(string s){
        int res=0;
        for(char c: s) if(c=='0') res++;
        return res;
    }
};