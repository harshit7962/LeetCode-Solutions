class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // if(nums.size()==1) return nums[0];
        int low=0, high=nums.size()-1;
        while(low<=high) {
            
            int mid = low + (high-low)/2;
            
            if((mid==0 || nums[mid]>nums[mid-1]) && (mid==nums.size()-1 || nums[mid]>nums[mid+1])) return mid;
            else if(mid>0 && nums[mid-1]>nums[mid+1]) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};