// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<int> st;
        st.push(0);
        long long res=0;
        for(int i=1;i<n;i++) {
            while(!st.empty() && arr[st.top()]>arr[i]) {
                int x = st.top();
                st.pop();
                if(!st.empty()) res = max(res, arr[x]*(i-st.top()-1));
                else res = max(res, arr[x]*(i));
            }
            st.push(i);
        }
        
        while(!st.empty()) {
            int x = st.top();
            st.pop();
            
            if(!st.empty()) res = max(res, arr[x]*(n-st.top()-1));
            else res = max(res, arr[x]*n);
        }
        
        return res;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends