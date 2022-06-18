// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool checkForCycle(vector<int> adj[], vector<bool> &vis, int src, int parent) {
    vis[src] = true;
    for(int y:adj[src]) {
        if(!vis[y]) {
            if(checkForCycle(adj, vis, y, src)) return true;
        } else if(y!=parent) return true;
    }
    
    return false;
}
    
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        vector<bool> vis(v, false);
        for(int i=0;i<v;i++){
            if(!vis[i]) if(checkForCycle(adj, vis, i, -1)) return true;
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