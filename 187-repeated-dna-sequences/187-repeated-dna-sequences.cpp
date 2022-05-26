class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10) return {};
        unordered_set<string> st;
        st.insert(s.substr(0, 10));
        unordered_set<string> res;
        for(int i=1;i<s.size()-9;i++) {
            if(st.count(s.substr(i, 10))>0) res.insert(s.substr(i, 10));
            st.insert(s.substr(i, 10));
        }
        
        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};