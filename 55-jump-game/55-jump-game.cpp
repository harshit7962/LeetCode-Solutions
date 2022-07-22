class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), rechable = nums[0];
        
        for(int i=1;i<n;i++) {
            if(rechable < i) return false;
            rechable = max(rechable, nums[i]+i);
        }
        
        return true;
    }
};