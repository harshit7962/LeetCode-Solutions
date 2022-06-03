class Solution {
public:
    int kadanes(vector<int> nums) {
        int sum=nums[0], maxsum=nums[0];
        for(int i=1;i<nums.size();i++) {
            if(sum<0) sum=0;
            sum+=nums[i];
            maxsum = max(maxsum, sum);
        }
        
        return maxsum;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int normalmax = kadanes(nums);
        cout << normalmax << " ";
        if(normalmax<=0) return normalmax;
        
        int sum=0;
        for(int i=0;i<nums.size();i++)  {
            sum+=nums[i];
            nums[i] = -nums[i];
        }
        
        int circularmax = sum+kadanes(nums);
        
        return max(circularmax, normalmax);
    }
};