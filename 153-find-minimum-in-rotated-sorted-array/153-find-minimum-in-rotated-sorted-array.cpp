class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        
        while(low<=high) {
            int mid = low + (high-low)/2;
            
            if(mid!=0 && nums[mid]<nums[mid-1]) return nums[mid];
            else if(nums[low]<=nums[mid] && nums[mid]>nums[high]) low = mid+1;
            else high = mid-1;            
        }
        
        return nums[low];
    }
};