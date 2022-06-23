// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
        //Dynamic Programming Array to store longest increasing subsequence till given index
        vector<int> dp(n, 1);
        for(int i=1;i<n;i++) {
            int res=0;
            for(int j=0;j<i;j++){
                if(a[j]<a[i]) {
                    res = max(res, dp[j]);
                }
            }
            dp[i] = res+1;
        }
        int res=dp[0];
        for(int i=0;i<n;i++) res=max(res, dp[i]);
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends