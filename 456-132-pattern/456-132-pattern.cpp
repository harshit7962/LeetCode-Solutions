class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> st;
        st.push({nums[0], nums[0]});
        
        for(int i=1;i<nums.size();i++) {
            int curr=st.top().second;
            while(!st.empty() && st.top().first<=nums[i]) st.pop();
            
            if(!st.empty() && st.top().second<nums[i]) return true;
            st.push({nums[i], min(curr, nums[i])});
        }
        
        return false;
    }
};