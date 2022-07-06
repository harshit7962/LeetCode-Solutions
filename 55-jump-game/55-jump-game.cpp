class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rechable = nums[0];
        
        for(int i=1;i<n;i++) {
            if(rechable<i) return false;
            rechable = max(rechable, nums[i]+i);
        }
        
        return rechable >= n-1;
    }
};