class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        bool isone=false;
        
        for(char c:s) mp[c]++;
        
        int res=0;
        for(auto x:mp){
            if(x.second&1) {
                isone=true;
                res--;
            } 
            res+=x.second;
        }
        if(isone) return res+1;
        return res;
    }
};