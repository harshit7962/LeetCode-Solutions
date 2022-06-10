class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int res=0, j=0;
        
        for(int i=0;i<s.size();i++) {
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=j) j=mp[s[i]]+1;
            mp[s[i]] = i;
            res = max(res, i-j+1);
        }
        
        if(s.size()-j > res) return s.size()-j;
        
        return res;
    }
};