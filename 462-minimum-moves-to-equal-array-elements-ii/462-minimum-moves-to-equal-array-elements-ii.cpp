class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), med;
        if(n&1) med = nums[n/2];
        else med = (nums[n/2]+nums[(n-1)/2])/2;
        
        int cost = 0;
        for(int i:nums) cost+=abs(i-med);
        
        return cost;
    }
};