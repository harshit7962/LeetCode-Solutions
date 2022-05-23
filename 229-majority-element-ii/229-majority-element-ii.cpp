class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for(auto i:nums) mp[i]++;
        
        vector<int> res;
        for(auto x:mp) {
            if(x.second>nums.size()/3) res.push_back(x.first);
        }
        
        return res;
    }
};