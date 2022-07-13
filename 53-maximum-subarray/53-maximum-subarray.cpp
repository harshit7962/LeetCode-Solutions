class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], curr_max = nums[0];
        
        for(int i=1;i<nums.size();i++) {
            curr_max = max(curr_max+nums[i], nums[i]);
            res = max(res, curr_max);
        }
        
        return res;
    }
};