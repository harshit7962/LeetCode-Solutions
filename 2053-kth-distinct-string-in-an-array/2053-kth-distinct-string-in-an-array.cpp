class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(auto s: arr) mp[s]++;
        
        
        for(auto s:arr) {
            if(mp[s]==1) k--;
            if(k==0) return s;
        }
        
        return "";
    }
};