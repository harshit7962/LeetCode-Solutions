class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for(int i:nums) total+=i;
        
        if(total==x) return nums.size();
        if(total<x) return -1;
        
        //Now we need to find the longest subarray with sum = total-x
        int target = total-x, curr_sum=0, start=0, max_size=0;
        
        for(int i=0;i<nums.size();i++) {
            curr_sum+=nums[i];
            while(curr_sum > target) curr_sum-=nums[start++];
            if(curr_sum==target) max_size = max(max_size, i-start+1);
        }
        
        if(max_size==0) return -1;
        return nums.size()-max_size;
    }
};