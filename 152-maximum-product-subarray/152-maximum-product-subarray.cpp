class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minp = nums[0], maxp = nums[0], res = nums[0];
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i] == 0) {
                minp = 1;
                maxp = 1;
                res = max(res, 0);
                continue;
            }
            
            int temp = maxp;
            
            maxp = max(minp*nums[i], max(maxp*nums[i], nums[i]));
            minp = min(minp*nums[i], min(temp*nums[i], nums[i]));
            
            res = max(res, maxp);
        }
        
        return res;
    }
};