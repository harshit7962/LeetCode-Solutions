class Solution {
public:
    
    bool interleaved(string s1, string s2, string s3, int i, int j, int k, vector<vector<vector<int>>> &dp) {
        if(dp[i][j][k] == 0) return false;
        if(dp[i][j][k] == 1) return true;
        
        if(k == s3.size()) return true;
        
        if(i<s1.size() && s1[i]==s3[k]) {
            if(interleaved(s1, s2, s3, i+1, j, k+1, dp)) return dp[i][j][j] = true;
        }
        
        if(j<s2.size() && s2[j]==s3[k]) {
            if(interleaved(s1, s2, s3, i, j+1, k+1, dp)) return dp[i][j][k] = true;
        }
        
        return dp[i][j][k] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<vector<int>>> dpmemo(101, vector<vector<int>>(101, vector<int>(201, -1)));
        
        return interleaved(s1, s2, s3, 0, 0, 0, dpmemo);
    }
};