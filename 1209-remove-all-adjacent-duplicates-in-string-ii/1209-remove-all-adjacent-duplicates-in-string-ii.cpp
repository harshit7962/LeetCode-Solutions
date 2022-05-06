class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        
        for(int i=0;i<s.size();i++) {
            if(st.size()==0) st.push({s[i],1});
            else if(s[i]==st.top().first) {
                st.top().second++;
                if(st.top().second==k) st.pop();
            }
            else st.push({s[i], 1});
        }
        string res="";
        while(st.size()!=0) {
            for(int i=0;i<st.top().second;i++) res+=st.top().first;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};