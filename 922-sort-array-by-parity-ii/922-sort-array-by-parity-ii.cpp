class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res(nums.size());
        
        int e=0, o=1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]&1) {
                res[o] = nums[i];
                o+=2;
            } else {
                res[e] = nums[i];
                e+=2;
            }
        }
        return res;
    }
};