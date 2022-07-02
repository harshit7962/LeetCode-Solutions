class Solution {
public:
    bool isSubsequence(string s, string t) {
        int curr=0;
        for(int i=0;i<t.size() && curr<s.size();i++) {
            if(t[i] == s[curr]) curr++;
        }
        
        return curr==s.size();
    }
};