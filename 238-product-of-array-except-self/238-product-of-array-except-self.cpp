class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count = 0, prod = 1;
        
        for(int i:nums) {
            if(i==0) {
                ++zero_count;
            } else {
                prod*=i;
            }
        }
        
        if(zero_count>1) {vector<int> res(nums.size(), 0); return res;}
        
        if(zero_count == 1) {
            vector<int> res(nums.size(), 0);
            for(int i=0;i<nums.size();++i) {
                if(nums[i]==0) {res[i] = prod; return res;}
            }
        }
        vector<int> res(nums.size());
        for(int i=0;i<nums.size();++i) {
            res[i] = prod/nums[i];
        }
        
        return res;
    }
};