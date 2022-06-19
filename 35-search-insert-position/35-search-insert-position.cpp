class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res=nums.size(), high=nums.size()-1, low=0;
        while(low<=high) {
            int mid = (low+high)/2;
            
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) {
                res = mid;
                high = mid-1;
            } else low=mid+1;
        }
        
        return res;
    }
};