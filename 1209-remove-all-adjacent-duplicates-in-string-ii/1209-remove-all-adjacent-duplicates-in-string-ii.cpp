class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(int i=0;i<s.size();i++) {
            if(st.empty() || st.top().first!=s[i]) {
                st.push({s[i], 1});
            } else {
                st.top().second++;
                if(st.top().second==k) st.pop();
            }
        }
        string res="";
        while(!st.empty()) {
            while(st.top().second>0) {
                res+=st.top().first;
                st.top().second--;
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};