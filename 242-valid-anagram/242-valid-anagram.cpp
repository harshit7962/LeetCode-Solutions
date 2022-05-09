class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> v(26, 0);
        
        for(auto c:s) v[c-'a']++;
        for(auto c:t) {
            if(v[c-'a']>0) v[c-'a']--;
            else return false;
        }
        
        return true;
    }
};