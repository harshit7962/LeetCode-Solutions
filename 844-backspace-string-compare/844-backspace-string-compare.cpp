class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="", s2="";
        for(char c:s){
            if(c=='#') { 
                if(s1.size()!=0) s1.pop_back();
            }
            else s1+=c;
        }
        
        for(char c:t) {
            if(c=='#') {
                if(s2.size()!=0) s2.pop_back();
            }
            else s2+=c;
        }
        
        
        return s1==s2;
    }
};