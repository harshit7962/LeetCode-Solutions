class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()<=1) return 0;
        sort(nums.begin(), nums.end());
        int res=0;
        if(k!=0) {
            int i=0, j=1;
            while(j<nums.size()) {
                if(nums[i]==nums[j]) j++;
                else if(nums[j]-nums[i]==k) {
                    res++;
                    while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
                    while(j+1<nums.size() && nums[j]==nums[j+1]) j++;
                    i++;
                    j++;
                } else if(nums[j]-nums[i]<k) j++;
                else if(nums[j]-nums[i]>k) i++;
            }
        } else {
            for(int i=0;i<nums.size();i++) {
                if(i+1<nums.size() && nums[i]==nums[i+1]) {
                    res++;
                    while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
                }
            }
        }
        
        
        
        return res;
    }
};