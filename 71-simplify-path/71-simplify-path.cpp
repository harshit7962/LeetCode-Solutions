class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        st.push("/");
        
        string curr="";
        for(int i=1;i<path.size();i++) {
            if(path[i]!='/') curr+=path[i];
            else if(path[i]=='/') {
                if(curr==".") {
                    st.pop();
                }
                else if(curr=="..") {
                    st.pop();
                    if(!st.empty()) st.pop();
                } else {
                    if(curr.size()!=0) st.push(curr);
                }
                if(st.empty() || st.top()!="/") st.push("/");
                curr="";
            }
        }
        if(curr==".") {
            st.pop();
        }
        else if(curr=="..") {
            st.pop();
            if(!st.empty()) st.pop();
        } else {
            if(curr.size()!=0) st.push(curr);
        }
        curr="";
        
        while(!st.empty()) {
            curr=st.top()+curr;
            st.pop();
        }
        
        if(curr[0]!='/') curr='/'+curr;
        if(curr[curr.size()-1]=='/') curr.pop_back();
        if(curr.size()==0) return "/";
        
        return curr;
    }
};