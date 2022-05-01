class Solution {
public:
    string converted(string s) {
        string res;
        for(char c:s) {
            if(c=='#') {
                if(res.size()!=0) res.pop_back();
            }
            else res+=c;
        }
        return res;
    }
    
    bool backspaceCompare(string s, string t) {
        return (converted(s)==converted(t));
    }
};