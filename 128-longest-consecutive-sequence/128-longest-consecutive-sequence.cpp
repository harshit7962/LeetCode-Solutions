class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1) return nums.size(); 
        sort(nums.begin(), nums.end());
        int res=0, curr=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==nums[i-1]+1) curr++;
            else if(nums[i]==nums[i-1]) continue;
            else {
                res=max(res, curr);
                curr=1;
            }
        }
        res=max(res, curr);
        return res;
    }
};