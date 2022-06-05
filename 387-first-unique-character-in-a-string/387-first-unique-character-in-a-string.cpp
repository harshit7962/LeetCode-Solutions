class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26, 0);
        for(char c:s) v[c-'a']++;
        
        for(int i=0;i<s.size();i++) if(v[s[i]-'a']==1) return i;
        
        return -1;
    }
};