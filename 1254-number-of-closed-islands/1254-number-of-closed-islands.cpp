class Solution {
public:
    bool touchBorder(vector<vector<int>> &grid, int i, int j) {
        if(grid[i][j]==1) return true;
        if(i<=0 || j<=0 || i>=grid.size()-1 || j>=grid[0].size()-1) return false;

        grid[i][j] = 1;
        bool flag1 = touchBorder(grid, i+1, j);
        bool flag2 = touchBorder(grid, i, j+1);
        bool flag3 = touchBorder(grid, i-1, j);
        bool flag4 = touchBorder(grid, i, j-1);
        
        return flag1 && flag2 && flag3 && flag4;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(), res=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    if(touchBorder(grid, i, j)) res++;
                    // cout << i << " " << j << " " << res << endl;
                }
            }
        }
        
        return res;
    }
};