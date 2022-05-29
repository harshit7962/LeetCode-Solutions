class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        int j=nums.size()-1;
        while(nums[j]==val) {
            j--;
            if(j<0) return 0;
        }
        
        int i=0;
        for(i=0;i<=j;i++) {
            if(nums[i]==val) {
                swap(nums[i], nums[j]);
                j--;
                while(nums[j]==val) j--;
            }
        }
        
        return i;
    }
};