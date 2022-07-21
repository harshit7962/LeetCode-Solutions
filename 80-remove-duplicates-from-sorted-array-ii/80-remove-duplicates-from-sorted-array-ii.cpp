class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=nums[curr]) {
                curr++;
                nums[curr] = nums[i];
            } else if(nums[i]==nums[curr] && (curr==0 || nums[curr-1]!=nums[curr])) {
                curr++;
                nums[curr] = nums[i];
            }
        }
        
        return curr+1;
    }
};