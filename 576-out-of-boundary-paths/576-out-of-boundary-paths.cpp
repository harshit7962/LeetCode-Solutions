class Solution {
public:    
    long dfs(int m, int n, int moves, int row, int col, vector<vector<vector<int>>>&memo) {
        if(row<0 || col<0 || row==m || col==n) return 1;
        if(moves == 0) return 0;
        
        if(memo[row][col][moves] >= 0) return memo[row][col][moves];

        memo[row][col][moves] = (
            (dfs(m, n, moves-1, row-1, col, memo)%1000000007 +
            dfs(m, n, moves-1, row+1, col, memo)%1000000007 +
            dfs(m, n, moves-1, row, col-1, memo)%1000000007 +
            dfs(m, n, moves-1, row, col+1, memo)%1000000007)%1000000007
        );
        return memo[row][col][moves];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return dfs(m, n, maxMove, startRow, startColumn, memo);
    }
};