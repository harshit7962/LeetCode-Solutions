class Solution {
public:
    bool isSafe(vector<vector<char>> &board, char k, int i, int j) {
        //Row Check
        for(int col=0;col<9;col++) if(board[i][col]==k) return false;
        
        //Col Check
        for(int row=0;row<9;row++) if(board[row][j]==k) return false;
        
        //Box Check
        int tr = (i/3)*3, lc = (j/3)*3;
        
        for(int x=tr;x<tr+3;x++) {
            for(int y=lc;y<lc+3;y++) {
                if(board[x][y]==k) return false;
            }
        }
        
        return true;
    }
    
    bool solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.') {
                    for(char k='1';k<='9';k++) {
                        if(isSafe(board, k, i ,j)) {
                            board[i][j] = k;
                            if(solveSudoku(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        
        
        return true;
    }
};