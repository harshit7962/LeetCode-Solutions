class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char c:s) mp[c]++;
        
        bool flag=false;
        int total=0;
        for(auto x:mp) {
            total+=x.second;
            if(x.second%2) {flag=true;total--;}
        }
        
        if(flag) return total+1;
        return total;
    }
};