// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector<int> search(string pat, string txt)
        {
            int hashpat=0, hashtxt=0;
            for(int i=0;i<pat.size();i++) {
                hashpat+=pat[i]-'A';
                hashtxt+=txt[i]-'A';
            }
            
            vector<int> res;
            if(hashpat==hashtxt && pat==txt.substr(0, pat.size())) res.push_back(1);
            for(int i=pat.size();i<txt.size();i++) {
                hashtxt+=(txt[i]-'A');
                hashtxt-=(txt[i-pat.size()]-'A');
                if(hashpat==hashtxt && pat==txt.substr(i-pat.size()+1, pat.size())) res.push_back(i-pat.size()+2);
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