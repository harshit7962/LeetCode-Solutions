class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, pair<int, int>> mp;
        
        int start=0;
        for(int i=0;i<s1.size();i++) {
            if(s1[i]==' ') {
                mp[s1.substr(start, i-start)].first++;
                start = i+1;
            }
        }
        mp[s1.substr(start)].first++;
        start=0;
        for(int i=0;i<s2.size();i++) {
            if(s2[i]==' ') {
                mp[s2.substr(start, i-start)].second++;
                start = i+1;
            }
        }
        mp[s2.substr(start)].first++;
        
        vector<string> res;
        for(auto x:mp) {
            if(x.second.first==1 && x.second.second==0) res.push_back(x.first);
            else if(x.second.first==0 && x.second.second==1) res.push_back(x.first);
        }
        
        return res;
    }
};