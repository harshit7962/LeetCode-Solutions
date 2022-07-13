class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        
        q.push({{entrance[0], entrance[1]}, 1});
        maze[entrance[0]][entrance[1]] = '+';
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            
            q.pop();
            
            if(row!=0 && maze[row-1][col]=='.') {
                if(row-1==0 || col==0 || row-1 == m-1 || col == n-1)  return dis;
                maze[row-1][col] = '+';
                q.push({{row-1, col},dis+1});
            }
            
            if(col!=0 && maze[row][col-1]=='.') {
                if(row==0 || col-1==0 || row == m-1 || col-1 == n-1)  return dis;
                maze[row][col-1] = '+';
                q.push({{row, col-1},dis+1});
            }
            
            if(row!=m-1 && maze[row+1][col]=='.') {
                if(row+1==0 || col==0 || row+1 == m-1 || col == n-1)  return dis;
                maze[row+1][col] = '+';
                q.push({{row+1, col},dis+1});
            }
            
            if(col!=n-1 && maze[row][col+1]=='.') {
                if(row==0 || col+1==0 || row == m-1 || col+1 == n-1)  return dis;
                maze[row][col+1] = '+';
                q.push({{row, col+1},dis+1});
            }
        }
        
        return -1;
    }
};