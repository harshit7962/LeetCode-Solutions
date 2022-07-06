class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, false);
        dp[0] = true;
        
        for(int i=1;i<n;i++) {
            for(int j=i-1;j>=0;j--) {
                if(j+nums[j]>=i && dp[j]) {dp[i] = true; break;}
            }
        }
        
        return dp[n-1];
    }
};