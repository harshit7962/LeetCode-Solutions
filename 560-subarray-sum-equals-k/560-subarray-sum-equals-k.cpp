class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int presum=0, res=0;
        for(int i=0;i<nums.size();i++) {
            presum+=nums[i];
            if(presum==k) res++;
            if(mp.find(presum-k)!=mp.end()) res+=mp[presum-k];
            mp[presum]++;
        }
        
        return res;
    }
};