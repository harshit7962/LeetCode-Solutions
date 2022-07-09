class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        
        deque<int> q;
        q.push_front(0);
        
        for(int i=1;i<nums.size();i++) {
            while(q.front()<i-k) q.pop_front();
            
            dp[i] = dp[q.front()] + nums[i];
            
            while(!q.empty() && dp[q.back()]<dp[i]) q.pop_back();
            
            q.push_back(i);
        }
        
        return dp[nums.size()-1];
    }
};