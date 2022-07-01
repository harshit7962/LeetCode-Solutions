class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row=mat.size(), col=mat[0].size();
        
        for(int i=0;i<col;i++) {
            for(int j=1;j<row;j++) {
                mat[j][i] += mat[j-1][i];
            }
        }
        
        for(int i=0;i<row;i++) {
            for(int j=1;j<col;j++) {
                mat[i][j] += mat[i][j-1];
            }
        }
        
        int row1, row2, col1, col2;
        vector<vector<int>> newmat(row, vector<int>(col, 0));
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                row1 = (i-k<0)?0:i-k;
                col1 = (j-k<0)?0:j-k;
                row2 = (i+k>=row)?row-1:i+k;
                col2 = (j+k>=col)?col-1:j+k;
                
                int wholesum = mat[row2][col2];
                int sub1 = (row1==0)?0:mat[row1-1][col2];
                int sub2 = (col1==0)?0:mat[row2][col1-1];
                int add1 = (row1==0 || col1==0)?0:mat[row1-1][col1-1];
                
                newmat[i][j] = wholesum+add1-sub1-sub2;
            }
        }
        
        
        return newmat;
    }
};