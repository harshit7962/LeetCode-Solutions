// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool checkForCycle(int src, int par, vector<bool>  &vis, vector<int> adj[]) {
        vis[src] = true;
        for(int y:adj[src]) {
             if(!vis[y]) {
                 if(checkForCycle(y, src, vis, adj)) return true;
             } else if(y!=par) return true;
        }
        
        return false;
    }
    
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        vector<bool> vis(v, false);
        for(int i=0;i<v;i++) {
            if(!vis[i]) if(checkForCycle(i,-1,vis,adj)) return true;
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends