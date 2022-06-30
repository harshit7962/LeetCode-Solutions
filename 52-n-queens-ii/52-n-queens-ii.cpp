class Solution {
public:
    int res=0;
    
    bool isSafe(vector<vector<char>> &board, int row, int col, int n) {
        //Checking if current row is free of Queens
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
        while(i<n && j>=0) {
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    void nQueens(vector<vector<char>> &board, int col, int n) {
        if(col>=n) {res++; return;}
        
        for(int i=0;i<n;i++) {
            if(isSafe(board, i, col, n)) {
                board[i][col]='Q';
                nQueens(board, col+1, n);
                board[i][col]='.';
            }
        }
        
        return;
    }
    
    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        
        nQueens(board, 0, n);
        
        return res;
    }
};