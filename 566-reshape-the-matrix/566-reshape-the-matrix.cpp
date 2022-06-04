class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> res;
        int m = mat.size(), n=mat[0].size(),p=0, q=0;
        if(m*n != r*c) return mat;
        
        for(int i=0;i<r;i++) {
            vector<int> temp;
            for(int j=0;j<c;j++) {
                temp.push_back(mat[p][q]);
                q++;
                if(q==n) {
                    p++;
                    q=0;
                };
            }
            res.push_back(temp);
        }
        return res;
    }
};