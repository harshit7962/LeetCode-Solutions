class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string, int> mp;
        
        
        for(string str: strs) {
            string curr = str;
            sort(curr.begin(), curr.end());
            
            if(mp.find(curr)==mp.end()) {
                res.push_back({str});
                mp.insert({curr, res.size()-1});
            } else {
                res[mp[curr]].push_back(str);
            }
        }
        
        
        return res;
    }
};