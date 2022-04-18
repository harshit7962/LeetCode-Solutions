class Solution {
public:
    string reverseWords(string s) {
        string curr="", res="";
        for(int i=0;i<s.size();i++) {
            if(s[i]==' ') {
                reverse(curr.begin(), curr.end());
                res+=curr+" ";
                curr="";
            } else {
                curr+=s[i];
            }
        }
        reverse(curr.begin(), curr.end());
        return res+curr;
    }
};