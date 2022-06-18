// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool checkForCycle(vector<int> adj[], vector<bool> &vis, vector<bool> &recst, int src) {
        vis[src] = true;
        recst[src] = true;
        
        for(int y:adj[src]) {
            if(!vis[y]) {
                if (checkForCycle(adj, vis, recst, y)) return true;
            } else if(recst[y]) return true;
        }
        
        
        recst[src] = false;
        
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        vector<bool> vis(v, false), recst(v,false);
        
        for(int i=0;i<v;i++) {
            if(!vis[i]) {
                if(checkForCycle(adj, vis, recst, i)) return  true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends