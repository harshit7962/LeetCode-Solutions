class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size()<8) return false;
        bool upper=false, lower=false, digit=false, special=false;
        unordered_set<char> st;
        st.insert('!');
        st.insert('@');
        st.insert('#');
        st.insert('$');
        st.insert('%');
        st.insert('^');
        st.insert('&');
        st.insert('*');
        st.insert('(');
        st.insert(')');
        st.insert('+');
        st.insert('-');
        
        for(int i=0;i<password.size();i++) {
            if(i!=0 && password[i]==password[i-1]) return false;
            if(password[i]>='A' && password[i]<='Z') upper=true;
            else if(password[i]>='a' && password[i]<='z') lower=true;
            else if(password[i]>='0' && password[i]<='9') digit=true;
            else if(st.count(password[i])==1) special=true;
        }
        
        return (upper && lower && digit && special);
    }
};