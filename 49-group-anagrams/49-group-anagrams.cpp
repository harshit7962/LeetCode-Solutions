class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        
        for(auto s:strs) {
            string curr = s;
            sort(curr.begin(), curr.end());
            mp[curr].push_back(s);
        }
        
        vector<vector<string>> res;
        for(auto pointer:mp) {
            res.push_back(pointer.second);
        }
        
        return res;
    }
};