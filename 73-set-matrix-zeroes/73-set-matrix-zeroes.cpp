class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> zeroRows, zeroCols;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j]==0) {
                    zeroRows.push_back(i);
                    zeroCols.push_back(j);
                }
            }
        }
        
        for(int rowNum:zeroRows) {
            for(int i=0;i<matrix[0].size();i++) matrix[rowNum][i]=0;
        }
        
        for(int colNum:zeroCols) {
            for(int i=0;i<matrix.size();i++) matrix[i][colNum]=0;
        }
    }
};