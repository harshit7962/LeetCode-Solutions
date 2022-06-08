class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=0, n=grid[0].size()-1;
        int res=0;
        while(m<grid.size() && n>=0) {
            if(grid[m][n]<0) {
                n--;
            } else {
                res+=(grid[0].size()-n-1);
                m++;
            }
        }
        
        if(n<0) res+=(grid.size()-m)*grid[0].size();
        
        return res;
    }
};