class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> mp;
        vector<vector<string>> res;
        
        string curr = strs[0];
        sort(curr.begin(), curr.end());
        mp.insert({curr, 0});
        res.push_back({strs[0]});
        
        int ind=0;
        for(int i=1;i<strs.size();i++) {
            string curr=strs[i];
            sort(curr.begin(), curr.end());
            if(mp.find(curr)==mp.end()) {
                mp[curr] = ++ind;
                res.push_back({strs[i]});
            }
            else {
                res[mp[curr]].push_back(strs[i]);
            }
            
        }
        return res;
    }
};