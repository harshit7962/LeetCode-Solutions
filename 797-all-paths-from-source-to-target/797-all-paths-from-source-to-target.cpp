class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>> graph, int src, int dest, vector<int> &path) {
        if(dest==src) {path.push_back(dest); res.push_back(path); path.pop_back(); return;}
        
        path.push_back(src);
        for(int y:graph[src]) {
            dfs(graph, y, dest, path);
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(graph, 0, graph.size()-1, path);
        return res;
    }
};