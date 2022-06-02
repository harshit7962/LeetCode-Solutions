class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int res=0;
        
        for(char c:s) {
            if(c=='(') st.push(c);
            else{
                if(st.empty()) res++;
                else st.pop();
            }
        }
        
        while(!st.empty()) {res++; st.pop();}
        
        return res;
    }
};