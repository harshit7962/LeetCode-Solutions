class Solution {
public:    
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++) {
            swap(matrix[i], matrix[n-i-1]);
        }
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};