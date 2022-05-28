class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mx=nums[0], mn=nums[0];
        for(int i=0;i<nums.size();i++) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        
        
        if(mx==mn) return 0;
        else return max(0, mx-mn-2*k);
    }
};