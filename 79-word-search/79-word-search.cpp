class Solution {
public:
    
    bool dfs(vector<vector<char>>&board, vector<vector<bool>> &visited, string word, int ind, int row, int col) {
        
        if(ind>=word.size()) return true;
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size()) return false;
        if(board[row][col]!=word[ind] || visited[row][col]) return false;
        
        visited[row][col] = true;

        //Up check
        if(dfs(board, visited, word, ind+1, row-1, col)) return true;
        
        //Down check
        if(dfs(board, visited, word, ind+1, row+1, col)) return true;
        
        //Left check
        if(dfs(board, visited, word, ind+1, row, col-1)) return true;
        
        //Right check
        if(dfs(board, visited, word, ind+1, row, col+1)) return true;
        
        /**
        If this current node is not part of our answer, we need to mark it unvisited...
        This is to make sure that this node can be used again for
        */
        visited[row][col] =false;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]) {                    
                    if(dfs(board, visited, word, 0, i, j)) return true;
                }
            }
        }
        
        
        return false;
    }
};