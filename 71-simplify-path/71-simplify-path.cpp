class Solution {
public:
    string simplifyPath(string path) {
        path=path+"/";
        stack<string> st;
        string curr="";
        
        for(int i=0;i<path.size();i++) {
            if(path[i]=='/') {
                if(curr=="..") {
                    if(!st.empty())
                        st.pop();
                } else if(curr!="." && curr!="")
                    st.push(curr);
                curr="";
            } else curr+=path[i];
        }
        if(st.empty()) return "/";
        curr="";
        while(!st.empty()) {
            curr="/"+st.top()+curr;
            st.pop();
        }
        
        return curr;
    }
};