class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int normalmax=nums[0], sum=nums[0], total=nums[0];
        
        nums[0]=-nums[0];
        for(int i=1;i<nums.size();i++) {
            if(sum<0) sum=0;
            sum+=nums[i];
            normalmax = max(normalmax, sum);
            total+=nums[i];
            nums[i] = -nums[i];
        }
        
        if(normalmax<=0) return normalmax;
        
        int circularmax=nums[0];
        sum=nums[0];
        
        for(int i=1;i<nums.size();i++) {
            if(sum<0) sum=0;
            sum+=nums[i];
            circularmax=max(circularmax, sum);
        }
        circularmax=total+circularmax;
        
        return max(circularmax, normalmax);
    }
};