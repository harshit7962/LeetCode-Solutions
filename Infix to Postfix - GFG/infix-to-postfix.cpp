// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    static bool higherprec(char c1, char c2) {
        if(c2=='(') return true;
        else if(c1=='^') return true;
        else if(c2=='^') return false;
        else if((c1=='/'||c1=='*') && (c2=='/'||c2=='*')) return false;
        else if(c1=='/'|| c1=='*') return true;
        return false;
    }
    
    string infixToPostfix(string s) {
        stack<char> st;
        
        string res ="";
        
        for(char c:s){
            if((c>='a'&&c<='z') || (c>='A' && c<='Z')) res+=c;
            else if(c=='(') {st.push(c);}
            else if(c==')') {
                while(st.top()!='(') {
                    res+=st.top();
                    st.pop();
                }
                st.pop();
            } else {
                if(st.empty()) st.push(c);
                else {
                    while(!st.empty() && !higherprec(c, st.top())) {
                        res+=st.top();
                        st.pop();
                    }
                    st.push(c);
                }
            }
        }
        
        while(!st.empty()) {res+=st.top();st.pop();};
        
        return res;
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends