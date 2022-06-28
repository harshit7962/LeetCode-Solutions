class Solution {
public:
    void visit(vector<int> adj[], vector<bool> &visited, int i) {
        visited[i]=true;
        queue<int> q;
        q.push(i);
        
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(int y:adj[x]) {
                if(!visited[y]) {
                    visited[y] = true;
                        q.push(y);
                }
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<bool> visited(n, false);
        int count=0;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                count++;
                visit(adj, visited, i);
            }
        }
        
        return count;
    }
};