class Solution {
public:
    vector<vector<string>> res;
    
    bool isSafe(vector<vector<char>> &board, int row, int col) {
        //checking if queen is already present in this row
        for(int i=0;i<col;i++) if(board[row][i]=='Q') return false;
        
        //Checking upper left diagonal
        int i=row, j=col;
        while(i>=0 && j>=0) {
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        
        //Checking lower left diagonal
        i=row, j=col;
        while(i<board.size() && j>=0) {
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    void addToResult(vector<vector<char>> &board, int n) {
        vector<string> ans;
        string curr="";
        for(int i=0;i<n;i++) {
            curr = "";
            for(int j=0;j<n;j++) {
                curr+=board[i][j];
            }
            ans.push_back(curr);
        }
        
        res.push_back(ans);
    }
    
    void nQueens(vector<vector<char>> &board, int col, int n) {
        if(col>=n) {addToResult(board, n); return;}
        
        for(int i=0;i<n;i++) {
            if(isSafe(board, i, col)) {
                board[i][col] = 'Q';
                nQueens(board, col+1, n);
                board[i][col] = '.';
            }
        }
        
        return;        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        
        nQueens(board, 0, n);
        
        return  res;
    }
};