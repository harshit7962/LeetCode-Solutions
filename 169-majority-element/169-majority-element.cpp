class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=0, count=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==nums[maj]) count++;
            else {
                count--;
                if(count==0) {
                    maj = i;
                    count=1;
                }
            }
        }
        return nums[maj];
    }
};