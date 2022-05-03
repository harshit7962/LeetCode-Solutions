class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num0 = 0, num1=0, num2=0, n=nums.size();
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) num0++;
            else if(nums[i]==1) num1++;
            else num2++;
        }
        
        for(int i=0;i<num0;i++) nums[i]=0;
        for(int i=num0;i<(num1+num0);i++) nums[i]=1;
        for(int i=(num1+num0); i<n;i++) nums[i]=2;
    }
};