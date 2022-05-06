// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    vector<int> v(52, 0);
	    string res="";
	    for(char i:str) {
	        if(i>='a' && i<='z') {
    	        if(v[i-'a']==0) {
	                res+=i;
	                v[i-'a']=1;
	            }
	        } else {
	            if(v[i-'A'+26]==0) {
	                res+=i;
	                v[i-'A'+26]=1;
	            }
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends