class Solution {
public:
    bool hasCycle(vector<vector<int>> &graph,vector<bool> &visited, vector<bool> &recst, vector<bool> &part, int src) {
        visited[src] = true;
        recst[src] = true;
        
        for(auto y:graph[src]) {
            if(!visited[y]) {
                if(hasCycle(graph, visited, recst, part, y)) {return part[src]=true;}
            } else if(recst[y]) {return part[src]=true;}
        }
        
        recst[src]= false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<bool> visited(n, false), recst(n, false), part(n, false);
        vector<int> res;
        
        for(int i=0;i<n;i++) {
            if(!visited[i]){
                hasCycle(graph, visited, recst, part, i);
            }
        }
        
        for(int i=0;i<n;i++) if(!part[i]) res.push_back(i);

        return res;
    }
};