class Solution {
public:
    
    bool dfs(vector<vector<int>>&graph, int src, vector<bool>&visited, vector<bool>&recst, vector<bool>&part) {
        visited[src] = true;
        recst[src] = true;
        
        for(int i:graph[src]) {
            if(!visited[i]) {
                if(dfs(graph, i, visited, recst, part)) {return part[src] = true;}
            }
            else if(recst[i]) {return part[src] = true;}
        }
        
        recst[src] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false), recst(n, false), part(n, false);
        
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(graph, i, visited, recst, part);
            }
        }
        
        vector<int> res;
        for(int i=0;i<n;i++) {
            if(!part[i]) res.push_back(i);
        }
        
        return res;
    }
};