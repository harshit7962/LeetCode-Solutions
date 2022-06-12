class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, nums[0]);
        
        for(int i=1;i<nums.size();i++) sum[i] = nums[i]+sum[i-1];
        
        if(sum[n-1]-sum[0]==0) return 0;
        for(int i=1;i<n;i++) {
            if(sum[i-1]==sum[n-1]-sum[i]) return i;
        }
        
        return -1;
    }
};