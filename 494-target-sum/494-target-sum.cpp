class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = target;
        
        for(int i:nums) sum+=i;
        
        if(sum%2 || sum<0) return 0;
        
        sum/=2;
        
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, 0));
        
        dp[0][0] = 1;
        
        for(int i=1;i<=nums.size();i++) {
            for(int j=0;j<=sum;j++){
                if(j-nums[i-1]>=0) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[nums.size()][sum];
    }
};