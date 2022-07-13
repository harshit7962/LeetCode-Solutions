class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        unordered_map<char, int> mp;
        
        for(char c: t) mp[c]++;
        
        int num_char = mp.size();
        
        int acquire = 0, release = 0;
        
        string res = "";
        
        while(acquire<s.size()) {
            if(mp.find(s[acquire])!=mp.end()) {
                mp[s[acquire]]--;
                if(mp[s[acquire]] == 0) num_char--;
            }
            
            while(num_char == 0) {
                if(res=="" || res.size()>acquire-release+1) {
                    res = s.substr(release, acquire-release+1);
                }
                
                if(mp.find(s[release])!=mp.end()) {
                    mp[s[release]]++;
                    if(mp[s[release]] == 1) num_char++;
                }
                release++;
            }

            acquire++;
        }
        
        if(num_char==0) {
            if(res=="" || res.size()>acquire-release+1) {
                res = s.substr(release, acquire-release+1);
            }
        }
        return res;
    }
};