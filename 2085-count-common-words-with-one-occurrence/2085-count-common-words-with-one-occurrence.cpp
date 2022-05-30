class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, pair<int, int>> mp;
        
        for(string s:words1) mp[s].first++;
        for(string s:words2) mp[s].second++;
        
        int res=0;
        for(auto x:mp) {
            if(x.second.first==1 && x.second.second==1) res++;
        }
        
        return res;
    }
};