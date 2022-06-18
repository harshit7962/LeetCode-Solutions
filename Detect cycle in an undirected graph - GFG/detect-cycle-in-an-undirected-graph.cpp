// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    bool DFS(int src, int parent, vector<int> adj[], vector<bool> &visited) {
        visited[src] = true;
        
        for(int &u : adj[src]) {
            if(visited[u] == false) {
                if(DFS(u, src, adj, visited))
                    return true;
            }
            else if(u != parent)
                return true;
        }
        
        return false;
    }
    
    bool checkDFS(vector<int> adj[], int V) {
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; ++i) {
            if(visited[i] == false) {
                if(DFS(i, -1, adj, visited))
                    return true;
            }
        }
        
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        return checkDFS(adj, V); 
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