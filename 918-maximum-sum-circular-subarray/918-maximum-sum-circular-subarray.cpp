class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int normal_sum=nums[0], curr=nums[0], total_sum=nums[0];
        nums[0]=-nums[0];
        for(int i=1;i<nums.size();i++){
            total_sum+=nums[i];
            if(curr<0) {
                curr = nums[i];
            } else {
                curr+=nums[i];
            }
            
            normal_sum = max(normal_sum, curr);
            nums[i]=-nums[i];
        }
        
        if(normal_sum<0) return normal_sum;
        
        int min_sum=nums[0], circular_sum=nums[0];
        for(int i=1;i<nums.size();i++) {
            if(min_sum<0) min_sum = nums[i];
            else min_sum+=nums[i];
            
            circular_sum = max(circular_sum,min_sum);
        }
        
        return max(normal_sum, total_sum+circular_sum);
    }
};