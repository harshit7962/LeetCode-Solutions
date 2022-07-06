class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string curr = "";
        
        int count=0;
        
        for(char c:s){
            if(c=='(') {
                st.push(c);
                curr+=c;
            }
            else if(c==')') {
                if(st.empty()) continue;
                else {st.pop();curr+=c;}
            }else curr+=c;
        }
        
        int onbounded_open = st.size();
        
        int ind = curr.size()-1;
        
        while(onbounded_open>0){
            if(curr[ind]=='(') {
                curr = curr.substr(0, ind) + curr.substr(ind+1);
                onbounded_open--;
            }
            ind--;
        }
        
        return curr;
    }
};