class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> smap(128,0), tmap(128,0);
        for(int i=0;i<s.size();i++) {
            if(smap[s[i]]!=tmap[t[i]]) return false;
            smap[s[i]]=i+1;
            tmap[t[i]]=i+1;
        }
        
        return true;
    }
};