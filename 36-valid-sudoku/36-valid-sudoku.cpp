class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> col(9), row(9), box(9);
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++) {
                char c = board[i][j];
                
                if(c=='.') continue;
                
                if(row[i].count(c)||col[j].count(c)||box[(i/3)*3 + j/3].count(c)) return false;
                
                row[i].insert(c);
                col[j].insert(c);
                box[(i/3)*3 + j/3].insert(c);
            }
        }
        
        return true;
    }
};