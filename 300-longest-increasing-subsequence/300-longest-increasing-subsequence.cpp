class Solution {
public:
    
    int findCeil(vector<int> &res, int k) {
        int ans, low=0, high=res.size()-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(res[mid]>=k) {ans=mid;high=mid-1;}
            else low=mid+1;
        }
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i]>res[res.size()-1]) res.push_back(nums[i]);
            else {
                int x = findCeil(res, nums[i]);
                res[x] = nums[i];
            }
        }
        
        return res.size();
    }
};