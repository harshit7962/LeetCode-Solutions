class Solution {
public:
    int numberOfAttacks(vector<vector<char>> board, int i, int j) {
        int res=0;
        for(int i1=i;i1>=0;i1--) {
            if(board[i1][j]=='B') break;
            else if(board[i1][j]=='p') {
                res++;
                break;
            }
        }
        for(int i1=i;i1<8;i1++) {
            if(board[i1][j]=='B') break;
            else if(board[i1][j]=='p') {
                res++;
                break;
            }
        }
        for(int j1=j;j1>=0;j1--) {
            if(board[i][j1]=='B') break;
            else if(board[i][j1]=='p') {
                res++;
                break;
            }
        }
        for(int j1=j;j1<8;j1++) {
            if(board[i][j1]=='B') break;
            else if(board[i][j1]=='p') {
                res++;
                break;
            }
        }
        return res;
    }
    
    int numRookCaptures(vector<vector<char>>& board) {
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                if(board[i][j]=='R') return numberOfAttacks(board, i, j);
            }
        }
        return -1;
    }
};