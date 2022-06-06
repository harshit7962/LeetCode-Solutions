class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> nge(n, n);
        
        stack<int> st;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--) {
            while(!st.empty() && nums[i]>=nums[st.top()]) st.pop();
            
            if(!st.empty()) nge[i] = st.top();
            st.push(i);
        }
        
        vector<int> res(n-k+1);
        int j=0;
        for(int i=0;i<=n-k;i++) {
            if(j<i) j=i;
            
            while(nge[j]<i+k) j = nge[j];
            
            res[i] = nums[j];
            
        }
        
        return res;
    }
};