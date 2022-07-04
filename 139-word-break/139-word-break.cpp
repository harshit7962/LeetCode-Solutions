class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string word:wordDict) st.insert(word);
        
        vector<bool> dp(s.size(), false);
        
        for(int i=0;i<s.size();i++) {
            if(st.count(s.substr(0, i+1))>0) {dp[i] = true; continue;}
            
            for(int j=0;j<i;j++) {
                if(dp[j] && st.count(s.substr(j+1, i-j))>0) {dp[i]=true; break;}
            }
        }
        
        return dp[s.size()-1];
    }
};