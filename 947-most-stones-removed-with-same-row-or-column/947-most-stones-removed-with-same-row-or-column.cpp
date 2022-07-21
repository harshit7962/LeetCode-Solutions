class Solution {
public:
    void dfs(vector<int> adj[], int src, vector<bool> &visited) {
        if(visited[src]) return;
        
        visited[src] = true;
        for(int y: adj[src]) {
            if(!visited[y]) dfs(adj, y, visited);
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        vector<int> adj[n];
        
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        
        int res = 0;
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                res++;
                dfs(adj, i, visited);
            }
        }
        
        return n-res;
    }
};