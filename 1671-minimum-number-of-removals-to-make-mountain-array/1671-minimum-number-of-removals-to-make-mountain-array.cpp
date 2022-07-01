class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> lis(n, 1), lds(n, 1);
        
        for(int i=1;i<n;i++) {
            int res=0;
            for(int j=0;j<i;j++) {
                if(nums[j]<nums[i]) res = max(res, lis[j]);
            }
            
            lis[i] = res+1;
        }
        
        for(int i=n-2;i>=0;i--) {
            int res=0;
            for(int j=i+1;j<n;j++) {
                if(nums[j]<nums[i]) res = max(res, lds[j]);
            }
            
            lds[i] = res+1;
        }
        
        int lbs = 0;
        for(int i=0;i<n;i++) {
            if(lis[i]!=1 && lds[i]!=1) lbs = max(lbs, lis[i]+lds[i]-1);
        }
        
        return n-lbs;
    }
};