class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        
        vector<int> dp1(nums.size(), 0), dp2(nums.size(), 0);
        
        for(int i=1;i<nums.size();i++) {
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j]) {
                    dp1[i] = max(dp1[i], dp2[j]+1);
                } else if(nums[i]<nums[j]) {
                    dp2[i] = max(dp1[j]+1, dp2[i]);
                }
            }
        }
        
        return 1+max(dp1[nums.size()-1], dp2[nums.size()-1]);
    }
};