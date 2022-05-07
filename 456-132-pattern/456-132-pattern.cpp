class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3) return false;
        stack<pair<int, int>> st;
        st.push({nums[0], nums[0]});
        
        for(int i=1;i<nums.size();i++) {
            int currMin = st.top().second;
            while(!st.empty() && st.top().first<=nums[i]) {
                st.pop();
            }
            if(!st.empty() && st.top().second<nums[i]) return true;
            
            st.push({nums[i], min(nums[i], currMin)});
        }
        
        return false;
        
    }
};