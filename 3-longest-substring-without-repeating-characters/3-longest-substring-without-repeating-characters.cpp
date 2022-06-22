class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        int i=0, j=1, res=1;
        unordered_set<char> st;
        st.insert(s[0]);
        while(j<s.size()) {
            while(st.count(s[j])>0) {
                st.erase(s[i++]);
            }
            st.insert(s[j++]);
            res = max(res, j-i);
        }
        
        return res;
    }
};