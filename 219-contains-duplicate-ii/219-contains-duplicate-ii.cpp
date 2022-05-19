class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        int n=nums.size();

        for(int i=0;i<=k&&i<n;i++) {
            mp[nums[i]]++;
            if(mp[nums[i]]>1) return true;
        }
        if(k>=n) return false;
        
        for(int i=k+1;i<n;i++) {
            mp[nums[i-k-1]]--;
            mp[nums[i]]++;
            if(mp[nums[i]]>1) return true;
        }
        return false;
    }
};