class Solution {
public:
    bool backspaceCompare(string s, string t) {
        while(s.find('#')!=-1) {
            if(s.find('#')==0) s = s.substr(1);
            else
                s = s.substr(0, s.find('#')-1) + s.substr(s.find('#')+1);
        }
        while(t.find('#')!=-1) {
            if(t.find('#')==0) t =t.substr(1);
            else
                t = t.substr(0, t.find('#')-1) + t.substr(t.find('#')+1);
        }    
        return t==s;
    }
};