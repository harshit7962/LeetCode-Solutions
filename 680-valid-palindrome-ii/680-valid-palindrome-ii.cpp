class Solution {
public:
    bool validPalindrome(string s, int k=0) {
        int i=0, j=s.size()-1;
        while(i<j) {
            if(s[i]==s[j]) {i++;j--;}
            else break;
        }
        if(i==j || i>j) return true;
        if(k==1) return false;
        return validPalindrome(s.substr(i, j-i), 1) || validPalindrome(s.substr(i+1, j-i),1);
    }
};