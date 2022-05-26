class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums1.size();i++) mp[nums1[i]]=-1;
        
        stack<int> st;
        st.push(nums2[0]);
        for(int i=0;i<nums2.size();i++) {
            while(!st.empty() && st.top()<nums2[i]) {
                if(mp.find(st.top())!=mp.end()) mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++) {
            nums1[i]=mp[nums1[i]];
        }
        
        return nums1;
    }
};