class Solution {
public:
    int findCiel(vector<int> &res, int n) {
        int ans = 0, low = 0, high = res.size()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            if(res[mid]>=n) {
                ans = mid;
                high = mid-1;
            } else low = mid+1;
        }
        
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> res;
        res.push_back(nums[0]);
        
        for(int i=1;i<n;i++) {
            if(nums[i] > res[res.size()-1]) res.push_back(nums[i]);
            else {
                res[findCiel(res, nums[i])] = nums[i];
            }
        }
        
        return res.size();
    }
};