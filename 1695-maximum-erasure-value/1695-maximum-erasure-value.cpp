class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int curr_sum=0, res=0;
        unordered_set<int> st;
        
        int i=0,j=0;
        while(j<nums.size()) {
            while(st.count(nums[j])>0) {
                st.erase(nums[i]);
                curr_sum-=nums[i];
                i++;
            }
            curr_sum+=nums[j];
            st.insert(nums[j++]);
            res = max(res, curr_sum);
        }
        
        return res;
    }
};