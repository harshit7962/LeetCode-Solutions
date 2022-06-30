class Solution {
public:
    int count=0;
    
    bool contains(int x, vector<int> &v) {
        for(int i=0;i<v.size();i++) if(v[i]==x) return true;
        return false;
    }
    
    void dfs(vector<int> directed[], vector<int> undirected[], vector<bool> &visited, int src) {
        visited[src] = true;
        
        for(int y:undirected[src]) {
            if(!visited[y]) {
                if(contains(y, directed[src])) {count++;}
                dfs(directed, undirected, visited, y);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> undirected[n], directed[n];
        
        for(int i=0;i<n-1;i++) {
            undirected[connections[i][0]].push_back(connections[i][1]);
            undirected[connections[i][1]].push_back(connections[i][0]);
            
            directed[connections[i][0]].push_back(connections[i][1]);
        }
        
        vector<bool> visited(n, false);
        
        dfs(directed, undirected, visited, 0);
        
        return count;
    }
};