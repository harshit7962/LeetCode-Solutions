class Solution {
public:
    void dfs(vector<vector<int>> &heights, vector<vector<int>> &ocean, int i, int j) {
        int m=heights.size(), n=heights[0].size();
        if(i<0||j<0||i>=m||j>=n||ocean[i][j]==-1) return;
        
        ocean[i][j]=-1;
        
        if(i!=0 && heights[i-1][j]>=heights[i][j]) dfs(heights, ocean, i-1, j);
        if(j!=0 && heights[i][j-1]>=heights[i][j]) dfs(heights, ocean, i, j-1);
        if(i!=m-1 && heights[i+1][j]>=heights[i][j]) dfs(heights, ocean, i+1, j);
        if(j!=n-1 && heights[i][j+1]>=heights[i][j]) dfs(heights, ocean, i, j+1);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        
        for(int col=0;col<n;col++) {
            if(pacific[0][col]==0) {dfs(heights, pacific, 0, col);}
            if(atlantic[m-1][col]==0) {dfs(heights, atlantic,m-1, col);}
        }
        
        for(int row=0;row<m;row++) {
            if(pacific[row][0]==0) {dfs(heights, pacific, row, 0);}
            if(atlantic[row][n-1]==0) {dfs(heights, atlantic, row, n-1);}
        }
        
        vector<vector<int>> res;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pacific[i][j]==-1 && atlantic[i][j]==-1) res.push_back({i, j});
            }
        }
        
        return res;
    }
};