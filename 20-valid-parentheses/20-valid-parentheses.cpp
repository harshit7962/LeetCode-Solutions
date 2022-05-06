class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else if(st.size()==0) return false;
            else if(s[i]==')' && st.top()=='(') st.pop();
            else if(s[i]==']' && st.top()=='[') st.pop();
            else if(s[i]=='}' && st.top()=='{') st.pop();
            else return false;
        }
        return st.size()==0;
    }
};