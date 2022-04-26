class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row(m);
        vector<int> col(n);
        
        for(int i=0;i<indices.size();i++) {
            row[indices[i][0]]++;
            col[indices[i][1]]++;
        }
        
        int res=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if((row[i]+col[j])&1) res++;
            }
        }
        return res;
    }
};