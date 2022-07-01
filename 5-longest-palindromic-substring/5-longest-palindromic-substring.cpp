class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int left, right;
        for(int i=0;i<s.size();i++) {
            //Checking for odd sized string
            left=i, right=i;
            while(left>=0 && right<s.size() && s[left]==s[right]) {
                if(res.size()<right-left+1) res = s.substr(left, right-left+1);
                left--;
                right++;
            }
            
            //Checking for even sized string
            left=i, right=i+1;
            while(left>=0 && right<s.size() && s[left]==s[right]) {
                if(res.size()<right-left+1) res = s.substr(left, right-left+1);
                left--;
                right++;
            }
        }
        
        return res;
    }
};