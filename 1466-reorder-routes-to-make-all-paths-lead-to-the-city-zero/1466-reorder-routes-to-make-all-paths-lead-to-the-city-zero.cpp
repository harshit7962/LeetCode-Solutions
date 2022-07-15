class Solution {
public:
    void dfs(vector<int> dir[], vector<int> und[], int &count, int src, vector<bool>&visited) {
        visited[src] = true;
        for(int y:und[src]) {
            if(!visited[y]) {
                bool isP = false;
                for(int i:dir[src]) {
                    if(i==y) {isP = true; break;}
                }
                
                if(isP) {count++;}
                dfs(dir, und, count, y, visited);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0;
        
        vector<int> undirected[n], directed[n];
        
        for(auto v: connections) {
            directed[v[0]].push_back(v[1]);
            
            undirected[v[0]].push_back(v[1]);
            undirected[v[1]].push_back(v[0]);
        }
        
        vector<bool> visited(n, false);
        dfs(directed, undirected, count, 0, visited);
        
        return count;
    }
};