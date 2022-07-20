class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int acquire=0, release=0, res=0;
        unordered_map<char, int> mp;
        
        while(acquire < s.size()) {
            while(mp[s[acquire]] == 1) {
                mp[s[release]]--;
                release++;
            }
            
            mp[s[acquire]]++;
            acquire++;
            
            res = max(res, acquire-release);
        }
        
        
        return res;
    }
};