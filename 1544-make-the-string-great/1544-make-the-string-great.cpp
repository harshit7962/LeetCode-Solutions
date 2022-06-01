class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char c:s) {
            if(!st.empty() && (c==st.top()-32||c==st.top()+32)) st.pop();
            else st.push(c);
        }
        
        string res = "";
        while(!st.empty()) {res=st.top()+res; st.pop();}
        return res;
    }
};