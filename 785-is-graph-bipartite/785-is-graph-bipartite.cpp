class Solution {
public:
    
    bool bfs(vector<vector<int>> &graph, vector<int> &color, int  src) {
        queue<int> q;
        
        q.push(src);
        color[src] = 0;
        
        while(!q.empty()) {
            int curr_node = q.front();
            q.pop();
            for(int y:graph[curr_node]) {
                if(color[y] == -1) {
                    q.push(y);
                    if(color[curr_node] == 0) color[y] = 1;
                    else color[y] = 0;
                } else if(color[y] == color[curr_node]) return true;
            }
        }
        
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i=0;i<n;i++) {
            if(color[i] == -1) {
                if(bfs(graph, color, i)) return false;
            }
        }
        
        return true;
    }
};