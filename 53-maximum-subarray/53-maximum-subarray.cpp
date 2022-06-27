class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0], sum=nums[0];
        
        for(int i=1;i<nums.size();i++) {
            if(sum<0) {
                sum=nums[i];
            } else{
                sum+=nums[i];
            }
            res = max(res, sum);
        }
        
        return res;
    }
};