class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int presum=0, res=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==1) presum++;
            else presum--;
            
            if(presum==0) res=i+1;
            if(mp.find(presum)!=mp.end()) res=max(res, i-mp[presum]);
            else mp[presum]=i;
        }
        
        return res;
    }
};