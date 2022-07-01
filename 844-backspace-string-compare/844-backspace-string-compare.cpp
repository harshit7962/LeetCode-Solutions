class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string res1="", res2="";
        for(char c: s) {
            if(c=='#') {if(res1.size()!=0) res1.pop_back();}
            else res1+=c;
        }
        
        for(char c: t) {
            if(c=='#') {if(res2.size()!=0) res2.pop_back();}
            else res2+=c;
        }
        
        return res1==res2;
    }
};