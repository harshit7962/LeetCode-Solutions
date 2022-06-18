class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int total_sum=0;
        for(int i:nums) total_sum+=i;
        
        int curr_sum=0;
        for(int i=0;i<n;i++) {
            if(total_sum-curr_sum-nums[i]==curr_sum) return i;
            curr_sum+=nums[i];
        }
        
        return -1;
    }
};