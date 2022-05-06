class Solution {
public:
    bool isSubstr(string s, string res) {
        for(int i=0;i<s.size();i=(i+res.size())) {
            if(s.substr(i, res.size())!=res) return false;
        }
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        string res=s.substr(0,1);
        int i=1;
        while(res.size()<=s.size()/2) {
            if (isSubstr(s, res)) return true;
            res+=s[i++];
        }
        return false;
    }
};