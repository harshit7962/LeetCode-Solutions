class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i:nums) st.insert(i);
        
        int res=0;
        for(int i=0;i<nums.size();i++) {
            if(st.count(nums[i]-1)==0) {
                int curr=1;
                while(st.count(nums[i]+curr)>0) curr++;
                res=max(res, curr);
            }
        }
        
        return res;
    }
};