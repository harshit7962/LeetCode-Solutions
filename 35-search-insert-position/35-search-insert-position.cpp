class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1, mid, res=-1;
        while(low<=high) {
            mid=(low+high)/2;
            if(nums[mid]==target) {
                return mid;
            } else if(nums[mid]>target) {
                high=mid-1;
            } else {
                res=mid;
                low=mid+1;
            }
        }

        return res+1;
    }

};