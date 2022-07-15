class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[2];
        
        for(int i=0;i<nums.size();i++) {
            int low = i+1, high = nums.size()-1;
            
            while(low<high) {
                int curr_sum  = nums[i]+nums[low]+nums[high];
                if(curr_sum - target == 0) return curr_sum;
                if(abs(curr_sum - target) < abs(res - target)) res = curr_sum;
                
                if(curr_sum > target) high--;
                else low++;
            }
        }
        
        return res;
    }
};