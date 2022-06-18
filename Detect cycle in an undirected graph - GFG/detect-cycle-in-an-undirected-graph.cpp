// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool checkCycle(vector<int> adj[], vector<bool> &vis, int src) {
        queue<pair<int, int>> q;
        q.push({src,-1});
        vis[src]=true;
        while(!q.empty()) {
            int x = q.front().first;
            int par = q.front().second;
            q.pop();
            for(int y:adj[x]) {
                if(!vis[y]) {
                    q.push({y,x});
                    vis[y] = true;
                } else if(y!=par) return true;
            }
        }
    
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        vector<bool> vis(v, false);
        for(int i=0;i<v;i++) {
            if(!vis[i]) {
                if(checkCycle(adj, vis, i)) return true;
            }
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