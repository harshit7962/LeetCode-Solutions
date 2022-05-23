class Solution {
public:
    bool checkContains(string s, unordered_map<string, int> mp, int wordSize) {
        for(int i=0;i<=s.size()-wordSize;i=i+wordSize) {
            string curr = s.substr(i, wordSize);
            if(mp[curr]>0) mp[curr]--;
            else return false;
        }
        for(auto x:mp) if(x.second!=0) return false;
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        for(string str:words) mp[str]++;
        
        int windowSize = words[0].size()*words.size();
        
        if(s.size()<windowSize) return {};
        
        vector<int> res;
        
        for(int i=0;i<=s.size()-windowSize;i++) {
            string curr=s.substr(i, windowSize);
            if(checkContains(curr, mp, words[0].size())) res.push_back(i);
        }
        return res;
    }
};