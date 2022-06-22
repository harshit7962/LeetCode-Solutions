class Solution {
public:
    string reverseWords(string s) {
        int start=0, curr=1;
        while(curr<s.size()) {
            if(s[curr]==' '){
                reverse(s.begin()+start,s.begin()+curr);
                curr++;
                start=curr;
            }
            curr++;
        }
        
        reverse(s.begin()+start, s.end());
        
        return s;
    }
};