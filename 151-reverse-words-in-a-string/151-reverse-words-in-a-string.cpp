class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        while(s[i]==' ') i++;
        s.erase(s.begin(), s.begin()+i);
        
        i=s.size()-1;
        while(s[i--]==' ') s.pop_back();
        
        for(int i=0;i<s.size();i++) {
            while(s[i]==' ' && s[i+1]==' ') {
                s.erase(i+1, 1);
            }
        }
        
        
        int curr=0;
        for(int i=1;i<s.size();i++) {
            if(s[i]==' ') {
                reverse(s.begin()+curr, s.begin()+i);
                curr=i+1;
            }
        }
        reverse(s.begin()+curr, s.end());
        reverse(s.begin(), s.end());
        
        return s;
    }
};