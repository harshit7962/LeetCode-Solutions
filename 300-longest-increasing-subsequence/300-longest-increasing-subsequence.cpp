class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for(int i=1;i<n;i++) {
            int res=0;
            for(int j=0;j<i;j++) {
                if(nums[j]<nums[i]) res = max(res, dp[j]);
            }
            
            dp[i] = res+1;
        }
        
        int res=0;
        for(int i:dp) res=max(res, i);
        
        return res;
    }
};