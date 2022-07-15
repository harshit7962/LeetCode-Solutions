class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(vector<vector<int>> &graph, int src, vector<int> &path) {
        path.push_back(src);
        
        if(src == graph.size()-1) {res.push_back(path);}
        
        for(int y:graph[src]) {
            dfs(graph, y, path);
        }
        
        path.pop_back();
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        
        dfs(graph, 0, path);
        
        return res;
    }
};