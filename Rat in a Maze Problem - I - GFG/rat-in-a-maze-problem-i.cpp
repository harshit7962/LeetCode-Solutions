// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void isRechable(vector<vector<int>> &m, vector<string> &res, int i=0, int j=0, string curr="") {
        if(i<0 || j<0 || i>=m.size() || j>=m.size() || m[i][j]==0) return;
        
        if(i==m.size()-1 && j==m.size()-1 && m[i][j]==1) {
            res.push_back(curr);
            return;
        } 
        
        m[i][j]=0;
        isRechable(m, res, i+1, j, curr+"D");
        isRechable(m, res, i-1, j, curr+"U");
        isRechable(m, res, i, j+1, curr+"R");
        isRechable(m, res, i, j-1, curr+"L");
        m[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        isRechable(m, res, 0, 0);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends