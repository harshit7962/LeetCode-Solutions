class Solution {
public:
    
    void dfs(vector<int> adj[], vector<bool> &visited, int s) {
        visited[s]=true;
        
        for(auto x:adj[s]) {
            if(!visited[x]) {
                dfs(adj, visited, x);
            }
        }
    }
    
    int connectedCompo(vector<vector<int>> &connections, int n) {
        vector<bool> visited(n, false);
        vector<int> adj[n];
        for(auto v: connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        int count=0;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                count++;
                dfs(adj, visited, i);
            }
        }
        
        return count;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int num_wires = connections.size();
        if(num_wires<n-1) return -1;
        
        return connectedCompo(connections, n)-1;
    }
};