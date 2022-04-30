class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            if(i%2==0 && nums[i]%2==1) {
                int j=i+1;
                for(;;j++)
                    if(nums[j]%2==0) break;
                swap(nums[i], nums[j]);
            } else if(i%2==1 && nums[i]%2==0) {
                int j=i+1;
                for(;;j++)
                    if(nums[j]%2==1) break;
                swap(nums[i], nums[j]);
            }
        }
        
        return nums;
    }
};