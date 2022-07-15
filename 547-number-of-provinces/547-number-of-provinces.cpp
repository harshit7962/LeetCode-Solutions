class Solution {
public:
    
    void dfs(vector<int> adj[], int src, vector<bool>&vis) {
        if(vis[src]) return;
        vis[src] = true;
        
        for(int y:adj[src]) {
            dfs(adj, y, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j]==1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int count = 0;
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                count++;
                dfs(adj, i, visited);
            }
        }
        
        return count;
    }
};