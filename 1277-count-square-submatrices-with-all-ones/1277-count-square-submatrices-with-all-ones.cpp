class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        
        int res=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]==1) {
                    int left = (i==0)?0:matrix[i-1][j];
                    int up = (j==0)?0:matrix[i][j-1];
                    int diag = (i==0 || j==0)?0:matrix[i-1][j-1];
                    
                    matrix[i][j] = 1+min(left,  min(up, diag));
                    res+=matrix[i][j];
                }
            }
        }
        
        return res;
    }
};