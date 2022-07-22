class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        
        for(int i=0;i<s.size();i++) {
            //Odd Sized palindromic substrings
            int left = i-1, right = i+1;
            while(left>=0 && right<s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if(res.size() < right-left-1) res = s.substr(left+1, right-left-1);
            
            left = i, right = i+1;
            while(left>=0 && right<s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if(res.size() < right-left-1) res = s.substr(left+1, right-left-1);
        }
        
        return res;        
    }
};