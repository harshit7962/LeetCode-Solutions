class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        mp.insert({nums[0], 0});
        
        for(int i=1;i<nums.size();i++) {
            if(mp.find(target-nums[i])!=mp.end()) {
                return {mp[target-nums[i]], i};
            } else {
                mp[nums[i]] = i;
            }
        }
        return {-1,-1};
    }
};