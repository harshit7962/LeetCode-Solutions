class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int release=0, acquire=0, res=0;
        while(acquire<nums.size()) {
            if(nums[acquire]==0) {
                while(release<=acquire && k==0) {
                    if(nums[release]==0) k++;
                    release++;
                }
                if(k==0) release++;
                else k--;
            }
            
            acquire++;
            res = max(res, acquire-release);
        }
        
        return res;
    }
};