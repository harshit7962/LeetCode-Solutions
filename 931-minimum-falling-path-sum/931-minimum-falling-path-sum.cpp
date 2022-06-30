class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<n;j++) {
                int prec_min = INT_MAX;
                if(j==0) {
                    prec_min = min(matrix[i-1][j], matrix[i-1][j+1]);
                } else if(j==n-1) {
                    prec_min = min(matrix[i-1][j-1], matrix[i-1][j]);
                } else {
                    prec_min = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i-1][j+1]));
                }
                
                matrix[i][j] += prec_min;
            }
        }
        
        int res=INT_MAX;
        for(int i=0;i<n;i++) {
            res = min(res, matrix[n-1][i]);
        }
        
        return res;
    }
};