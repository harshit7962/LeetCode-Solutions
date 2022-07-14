class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        
        int left, right;
        for(int i=0;i<s.size();i++) {            
            //Odd sized palindromes
            left =i-1, right=i+1;
            while(left>=0 && right<s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if(res.size()<right-left-1) res = s.substr(left+1, right-left-1);
            
            //Even sized palindromes
            left = i, right = i+1;
            while(left>=0 && right<s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if(res.size()<right-left-1) res = s.substr(left+1, right-left-1);
        }
        
        return res;
    }
};