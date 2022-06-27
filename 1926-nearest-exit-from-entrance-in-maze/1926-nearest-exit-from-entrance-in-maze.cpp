class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(), n=maze[0].size();
        queue<pair<pair<int, int>, int>> q;
        
        q.push({{entrance[0], entrance[1]}, 0});
        
        maze[entrance[0]][entrance[1]] = '+';
        
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int c = q.front().second;
            
            q.pop();
             
            //Moving Up
            if(i!=0 && maze[i-1][j]=='.') {
                if(i-1==m-1 || i-1==0 || j==0|| j==n-1) return c+1;
                maze[i-1][j] = '+';
                q.push({{i-1, j},c+1});
            }
            
            //Moving Down
            if(i!=m-1 && maze[i+1][j]=='.') {
                if(i+1==m-1 || i+1==0 || j==0|| j==n-1) return c+1;
                maze[i+1][j] = '+';
                q.push({{i+1,j},c+1});
            }
            
            //Moving Left
            if(j!=0 && maze[i][j-1]=='.') {
                if(i==m-1 || i==0 || j-1==0|| j-1==n-1) return c+1;
                maze[i][j-1] ='+';
                q.push({{i, j-1}, c+1});
            }
            
            //Moving Right
            if(j!=n-1 && maze[i][j+1]=='.') {
                if(i==m-1 || i==0 || j+1==0|| j+1==n-1) return c+1;
                maze[i][j+1]='+';
                q.push({{i,j+1}, c+1});
            }
        }
        
        
        return -1;
    }
};