class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1, first=-1, last=-1;
        while(low<=high) {
            int mid = (high+low)/2;
            if(nums[mid]>=target) {
                if(nums[mid]==target) first=mid;
                high=mid-1;
            } 
            if(nums[mid]<target) {
                low=mid+1;
            }
        }
        
        low=0, high=nums.size()-1;
        while(low<=high) {
            int mid = (low+high)/2;
            if(nums[mid]>target) high=mid-1;
            else {
                if(nums[mid]==target) last = mid;
                low=mid+1;
            }
        }
        return {first, last};
    }
};