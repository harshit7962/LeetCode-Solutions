class Solution {
public:
    
    bool targetSum(vector<int>&  nums, int target) {
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target+1, false));
        
        for(int i=0;i<=nums.size();i++) dp[i][0] = true;
        
        for(int i=1;i<=nums.size();i++) {
            for(int j=1;j<=target;j++) {
                if(j-nums[i-1]>=0) {
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i-1]]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[nums.size()][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i:nums) sum+=i;
        
        if(sum%2) return false;
        
        return targetSum(nums, sum/2);
    }
};