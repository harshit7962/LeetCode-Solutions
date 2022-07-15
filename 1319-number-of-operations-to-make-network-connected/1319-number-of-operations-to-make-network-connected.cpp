class Solution {
public:
    void dfs(vector<int> adj[], int src, vector<bool> &vis) {
        if(vis[src]) return;
        vis[src] = true;
        
        for(int y:adj[src]) {
            dfs(adj, y, vis);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int> adj[n];
        
        for(auto v: connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                count++;
                dfs(adj, i, visited);
            }
        }
        
        return count-1;
    }
};