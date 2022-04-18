class Solution {
public:
    string reverseWords(string s) {
        int l=0,r=1;
        for(int i=1;i<s.size();i++) {
            if(s[i]==' ') {
                reverse(s.begin()+l, s.begin()+r);
                l=r+1;
                r=l;
            } else {
                r++;
            }
        }
        reverse(s.begin()+l, s.begin()+r);
        return s;
    }
};