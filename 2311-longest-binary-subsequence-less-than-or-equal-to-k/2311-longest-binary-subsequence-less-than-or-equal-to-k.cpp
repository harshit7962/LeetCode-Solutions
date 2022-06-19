class Solution {
public:
    int binToDec(string str) {
        if(str=="") return 0;
        reverse(str.begin(), str.end());
        int res=0;
        for(int i=0;i<str.length();i++) {
            if(str[i]=='1') res+=pow(2, i);
        }
        
        return res;
    }
    
    int longestSubsequence(string s, int k) {
        int i=0, j=0, res=0;
        string curr="";
        int num_zeros=0;
        while(j<s.size()) {
            if(i>j) j=i;
            
            curr = s.substr(i,j-i+1);
            if(binToDec(curr)<=k) {
                if(curr.size()+num_zeros>res) res = curr.size()+num_zeros;
                j++;
            } else {
                if(s[i]=='0') num_zeros++;
                i++;
            }
            
            
        }
        
        return res;
    }
};