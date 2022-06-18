// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        int count=0;
        vector<int> inDegree(v, 0);
        
        for(int i=0;i<v;i++) 
        for(int x:adj[i]) inDegree[x]++;
        
        queue<int> q;
        
        for(int i=0;i<v;i++) if(inDegree[i]==0) q.push(i);
        
        while(!q.empty()) {
            count++;
            int x = q.front();
            q.pop();
            for(int y:adj[x]) {
                if(inDegree[y]==1) q.push(y);
                else inDegree[y]--;
            }
        }
        
        return count!=v;
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