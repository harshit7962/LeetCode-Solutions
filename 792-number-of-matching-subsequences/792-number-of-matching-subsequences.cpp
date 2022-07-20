class Solution {
public:
    bool isMatching(string &s, string t) {
        int i=0, j=0;
        while(i<s.size() && j<t.size()) {
            if(s[i] == t[j]) j++;
            i++;
        }
        
        return j == t.size();
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;
        unordered_map<string, int> mp;
        for(string word:words) mp[word]++;
        
        for(auto x:mp) {
            if(isMatching(s, x.first)) cnt+=x.second;
        }
        
        return cnt;
    }
};