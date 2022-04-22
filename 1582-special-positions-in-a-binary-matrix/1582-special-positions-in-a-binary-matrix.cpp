class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rowSum(mat.size());
        vector<int> colSum(mat[0].size());
        
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                rowSum[i]+=mat[i][j];
                colSum[j]+=mat[i][j];
            }
        }
        
        int res = 0;
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                if(mat[i][j]==1 && rowSum[i]==1 && colSum[j]==1)
                    res++;
        
        return res;
    }
};