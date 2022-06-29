class Solution {
public:
    
    void dfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int i, int j) {
        if(i<0 || j<0 || i>=graph.size() || j>=graph[0].size() || visited[i][j]) return;
        
        visited[i][j]=true;
        
        //Moving Up
        if(i!=0 && graph[i][j]<=graph[i-1][j]) dfs(graph, visited, i-1, j);
        
        //Moving Down
        if(i!=graph.size()-1 && graph[i][j]<=graph[i+1][j]) dfs(graph, visited, i+1, j);
        
        //Moving right
        if(j!=graph[0].size()-1 && graph[i][j]<=graph[i][j+1]) dfs(graph, visited, i, j+1);
        
        //Moving left
        if(j!=0 && graph[i][j]<=graph[i][j-1]) dfs(graph, visited, i, j-1);
        
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m= heights.size(), n=heights[0].size();
        vector<vector<bool>> pacific_vis(m, vector<bool>(n, false)), atlantic_vis(m, vector<bool>(n, false));
        
        for(int i=0;i<n;i++) {
            dfs(heights, pacific_vis, 0, i);
            dfs(heights, atlantic_vis, m-1, i);
        }
        
        for(int i=0;i<m;i++) {
            dfs(heights, pacific_vis, i, 0);
            dfs(heights, atlantic_vis, i, n-1);
        }
        
        vector<vector<int>> res;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pacific_vis[i][j] && atlantic_vis[i][j]) res.push_back({i, j});
            }
        }
        
        return res;
    }
};