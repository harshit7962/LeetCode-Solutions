class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        
        string curr="";
        for(int i=0;i<strs[0].size();i++) {
            if(strs[0][i] == strs[strs.size()-1][i]) curr+=strs[0][i];
            else break;
        }
        
        return curr;
    }
};