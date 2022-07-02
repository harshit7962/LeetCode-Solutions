class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nextgreater(n, n);
        
        stack<int> st;
        st.push(0);
        
        for(int i=1;i<n;i++) {
            while(!st.empty() && nums[st.top()]<nums[i]) {
                nextgreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        vector<int> res(n-k+1);
        
        int j=0;
        for(int i=0;i<=n-k;i++) {
            if(j<i) j=i;
            
            while(nextgreater[j]<i+k) {
                j = nextgreater[j];
            }
            
            res[i] = nums[j];
        }
        
        return res;
    }
};