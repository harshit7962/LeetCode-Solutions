class Solution {
public:
    
    bool hasPath(vector<int> adj[], int src, int des, vector<bool> &vis) {
        if(src==des) return true;
        vis[src] = true;
        for(int y:adj[src]){
            if(!vis[y]) {
                if(hasPath(adj, y, des, vis)) return true;
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        
        return hasPath(adj, source, destination, visited);
    }
};