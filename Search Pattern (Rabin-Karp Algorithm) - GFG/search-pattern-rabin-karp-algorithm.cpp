// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector<int> search(string pat, string txt)
        {
            vector<int> res;
            for(int i=0;i<txt.size()-pat.size()+1;i++) {
                if(pat==txt.substr(i, pat.size())) res.push_back(i+1);
            }
            if(res.size()==0) return {-1};
            return res;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends