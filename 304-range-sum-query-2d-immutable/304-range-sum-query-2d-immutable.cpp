class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        for(int i=0;i<cols;i++){
            for(int j=1;j<rows;j++) {
                matrix[j][i] += matrix[j-1][i]; 
            }
        }
        
        for(int i=0;i<rows;i++) {
            for(int j=1;j<cols;j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        prefixSum = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int wholeSum = prefixSum[row2][col2];
        int sub1=0, sub2=0, add1=0;
        if(row1!=0) sub1=prefixSum[row1-1][col2];
        if(col1!=0) sub2=prefixSum[row2][col1-1];
        if(row1!=0 && col1!=0) add1 = prefixSum[row1-1][col1-1];
        
        return wholeSum-sub1-sub2+add1;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */