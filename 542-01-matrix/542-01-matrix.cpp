class Solution {
public:
    
    void simulBFS(vector<vector<int>> mat, vector<vector<int>> &res, queue<pair<int, int>> &q) {
        int count=-1;
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        while(!q.empty()) {
            int  c = q.size();
            count++;
            for(int x=0;x<c;x++) {
                int i=q.front().first;
                int j=q.front().second;
                
                q.pop();
                
                res[i][j]=count;
                
                if(i!=0 && mat[i-1][j]==1 && !visited[i-1][j]) {
                    visited[i-1][j]=true;
                    q.push({i-1, j});
                }
                if(j!=0 && mat[i][j-1]==1 && !visited[i][j-1]) {
                    visited[i][j-1]=true;
                    q.push({i, j-1});
                }
                if(i!=mat.size()-1 && mat[i+1][j]==1 && !visited[i+1][j]) {
                    visited[i+1][j]=true;
                    q.push({i+1, j});
                }
                if(j!=mat[0].size()-1 && mat[i][j+1]==1 && !visited[i][j+1]) {
                    visited[i][j+1]=true;
                    q.push({i, j+1});
                }
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        queue<pair<int, int>> q;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j]==0) q.push({i, j});
            }
        }
        
        simulBFS(mat, res, q);
        
        return res;
    }
};