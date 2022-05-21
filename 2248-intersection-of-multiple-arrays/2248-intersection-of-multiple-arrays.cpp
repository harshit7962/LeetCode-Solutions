class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> mp;
        
        for(int i=0;i<nums[0].size();i++) mp[nums[0][i]]++;
        
        for(int i=1;i<nums.size();i++)
            for(int j=0;j<nums[i].size();j++)
                mp[nums[i][j]]++;
        
        vector<int> res;
        for(auto i:mp) {
            if(i.second == nums.size()) res.push_back(i.first);
        }
        
        return res;
    }
};